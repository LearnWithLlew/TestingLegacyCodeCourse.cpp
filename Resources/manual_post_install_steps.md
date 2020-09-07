After these steps:

* install_script.ps1
* post_install_script.ps1

Do these:

* Tidy up Desktop - putting icons in to Links area
    * [Chrome] [BC4] [MobTime] [C:\Code] [Slides]
    * [Visual Studio] [GitHub] [VS Code] [Clion] [AnyDesk] or [Teams]
    * Note that AnyDesk will be in:
        * C:\ProgramData\chocolatey\lib\anydesk.portable\tools\
* Pin programs to Taskbar
    * [Chrome]
    * [Explorer]
        * Pin C:\Code folder
        * Pin C:\Code\TestingLegacyCodeCourse.slides
    * [GitHub]
    * [Clion]
    * [Visual Studio]
    * [VS Code]
    * [Notepad ++]
    * [AnyDesk] or [Teams]
    * [MobTime]
* Run CLion
    * Answer initial setup questions
* Run all the .vsix installers downloaded by post-install script
    * 2020-09-03 On a fast VM, some of these didn't download, due to Azure rate-limiting
* Run Visual Studio
    * Answer initial setup questions
    * Open "C:\Code\TestingLegacyCodeCourse.cpp\cmake-build-vs2019-x64\legacy_code_course.sln"
    * Configure Extensions
        * Change VSColour output to "I have donated" (Clare has donated)
        * Set up Catch2 test
            * Open Test Explorer
            * Load 
    * Startup is set to "Most recent solution"
    * Only the course.md file is open in Visual Studio
* Install PowerPoint - via Clare's work Microsoft 365 subscription
    * Set the number of recent files to show to 0
    * https://www.howtogeek.com/141490/how-to-clear-the-recent-documents-list-in-word-2013/
    * Uninstall OneDrive
* Make Chrome the default browser
* Log in to accounts
    * MindMup - with a non-admin account?

Do one of:
* Run Any Desk
* Log in to Teams