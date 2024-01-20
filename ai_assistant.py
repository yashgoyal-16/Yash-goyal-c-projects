import speech_recognition as sr
import os
from openai import OpenAI
import datetime 
from win32com.client import Dispatch
import webbrowser
 
speak = Dispatch("SAPI.SpVoice").Speak
vis = ""
def ai(prompt):
    print(f"Prompt to AI: {prompt}")

    client = OpenAI(
        api_key=os.getenv("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"),
    )

    response = client.chat.completions.create(
        messages=[
            {
                "role": "user",
                "content": prompt,
            }
        ],
        model="gpt-3.5-turbo",
    )

    print("OpenAI Response:")
    print(response)

    text = response["choices"][0]["message"]["content"]
    print(f"AI Response: {text}")

    say(text)


def say(text):
    speak(f"{text}")
def takeorder():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.pause_threshold = .8
        voice = r.listen(source)
        query = r.recognize_google(voice,  language= "en-in")
        if "open" in query.lower():
            webbrowser.open(f"https://{query[5:]}.com")
        if "start" in query.lower ():
            os.system(f'start "" "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\{query[6:]}.lnk"')
        if "the time" in query.lower():
            a = datetime.datetime.now().strftime("%H:%M:%S")  
            say(a)
        if "using artificial intelligence".lower() in query.lower():
            ai(prompt=query)        
        print(f"user said {query}")
        return query
    

x = " Zarvis here"
say(x)
print("Listening")
try:
    p = takeorder()
    say(p)
except:
    say("sorry i cant understand")




