##
This is the beginning of my "CLE" (Command-Line Environment) idea-- a terminal-like interface that looks something like VSCode, with side and top bars for quick access to other resources. It will have sound FX and other "personable" features. Perhaps years in the future, it could be an intriguing-enough way to interface one's computer that gets the next generation interested in computer science/engineering, IT, etc.. I'm going to start out by making a CLI with some "flare." I have no idea how to do this-- this is a research project that involves a lot of help from ChatGPT. Any code I don't write, I will break down and carefully go through, which should help me gain experience in systems programming. This will not be "vibe-coded." I will be actively involved with every aspect of development, going down each rabbit hole as it comes up. ChatGPT will not be a tool I use to make this app, it will be the instructor/teacher that guides my learning and project development process. 

This will be Windows-specific for now, I want to learn how to make a "CLE" for strictly one OS before I learn to make one portable.
##
I listen to random documentaries to fall asleep, and played one on South Asian/Indian religions a while ago. The name "Naga" refers to snake-like beings-- usually a combination of a human torso at the end of a large snake body/tail. They're found in Hinduism, Buddhism, and Jainism, and are always guardians of sorts, either of prominent religious figures, realms, or sacred teachings. The name stuck out to me, and I'm naming this project "Naga" simply because I love the name.
##



##
Paths--

In paths.cpp, the function resolvePath() is used to take any string that's passed into it and "normalize" it into an actual, absolute path. We can use std::getenv() to grab environment variables, in this case we're grabbing the "USERPROFILE" environment variable, which is the path to the user's home directory. We then join the relative path p with the absolute path we got from USERPROFILE to create/resolve the absolute path to the CWD. -- This is crucial for commands like "mkdir" and "cd" because when the user inputs a specific location, the computer (under the hood) turns that location (often just one word) into an entire absolute path that it can work with. Computers work in absolute paths in this regard.
##

##
"go" command--

"go" launches an application. In order to do so, we must take user input and format it in a way the Windows API can understand. This entails ensuring all input is in UTF16/Wide format, arguments are quoted properly, and arguments are together in one std::wstring. 