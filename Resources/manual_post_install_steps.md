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
        * If you get an error, close Visual Studio and re-open the .sln
    * Configure Extensions
        * Change VSColour output to "I have donated" (Clare has donated)
        * Enable ReSharper C++
            * Extensions -> ReSharper -> Why ReSharper is disabled -> Start Evaluation
        * Set up Catch2 test adapter - **Maybe**
            * Test -> Test Explorer
            * Options -> Configure Run Settings
            * Select Solution-Wide runsettings file
            * Open `Catch2Tests.runsettings`
        * Clean Build
        * Check that tests get shown in test adapter
        * If you have problems, go to Output and Show output fom Tests
            * Scroll to the bottom to see the newest output
    * Tools -> Options
        * Startup is set to "Most recent solution"
    * Only the course.md file is open in Visual Studio
* Log in to Microsoft 365 account to view slides
    * Add Slides to Chrome bookmarks bar
* Make Chrome the default browser
* Log in to accounts
    * MindMup - with a non-admin account?

Do one of:
* Run Any Desk
    * Enable unattended access
    * Note the machine ID and unattended access password in the course google doc  
* Log in to Teams

Final prep
* Create a branch for the course
* Launch VM
* Run AnyDesk
