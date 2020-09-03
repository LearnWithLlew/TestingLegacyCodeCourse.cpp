Afher these steps:

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
        * And Pin C:\Code folder
    * [GitHub]
    * [Clion]
    * [Visual Studio]
    * [VS Code]
    * [Notepad ++]
    * [AnyDesk] or [Teams]
    * [MobTime]
* Run all the .vsix installers downloaded by post-insall script
    * 2020-09-03 On a fast VM, some of these didn't download, due to Azure rate-limiting
* Run CLion
    * Answer initial setup questions
* Run Visual Studio
    * Answer initial setup questions
    * Open "C:\Code\TestingLegacyCodeCourse.cpp\cmake-build-vs2019-x64\legacy_code_course.sln"

Do one of:
* Run Any Desk
* Log in to Teams