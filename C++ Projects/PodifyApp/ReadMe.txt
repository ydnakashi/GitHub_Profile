Name & Student ID:
    Yuki Nakashima
    101189690

Purpose of Program:
    Simulates Podcast playlist application called Podify containing a list of podcasts. Podcasts contain episodes, simulated with audio 
    files and video files in a string form. Utilizes the Factory design pattern to facilitate episode and podcast generation.

Files Included:
    1. Podcast.cc, Podcast.h (Entity / Container object):
        (a) Contains Podcast meta-data as well as a collection of Episodes.
    2. Episode.cc, Episode.h (Entity): 
        (a) Contains Episode meta-data and content.
    3. Search.cc, Search.h (Behaviour object): 
        Virtual base class of all Search objects. 
        (a) H_Search (Behaviour object): Matches Episodes by the Podcast host.
        (b) C_Search (Behaviour object): Matches Episodes by the Podcast category. 
        (c) HorC_Search (Behaviour object): Matches Episodes by the Podcast host or category.
    4. Array.h (Container object): 
        (a) A simple (templated) data structure.
    5. Podify.cc, Podify.h (Control object): 
        (a) Stores Podcasts along with their Episodes, allows them to be queried.
    6. PodcastPlayer.cc, PodcastPlayer.h (Behaviour object):
        Determines how to play an Episode (either "audio" only, or "audio and video", both of which are simply text).
        (a) AudioPlayer: Displays the audio of an Episode.
        (b) VideoPlayer: Displays the audio of an Episode and some ASCII art which is loaded from a file at runtime.
    7. View.cc, View.h (View object):
        (a) Collects user input and displays Podcasts, Episodes and other information.
    8. Control.cc, Control.h (Control object): 
        (a) Manages the interactions of Podify, PodcastFactory, and View. Stores the Episode playlist.
    9. TestControl.cc, TestControl.h (Control object): 
        (a) Test framework for Podify.
    10. Tester.cc, Tester.h: 
        (a) Provides some common test functionality.
    11. classa2.py
        (a) Generates templated C++ source files to facilitate programming

Libraries Used:
    iostream
    string
    iomanip
    vector
    fstream
    limits

Compilation Instructions:
    To get final executable a5 and a5test, enter in terminal
        make

    To execute executables, enter in terminal
        ./a5
        ./a5test
    
    To delete all object files of classes, enter in terminal
        make clean
    
Notes:
    
