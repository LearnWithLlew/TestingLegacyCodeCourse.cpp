# Manual Post-install Steps

## Reminder: Initial Setup

After these steps:

* install_script.ps1
* post_install_script.ps1

Do these:

## General Steps

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

## CLion

* Run CLion
    * Answer initial setup questions
* Set up code coverage - see [CLion section of these instructions](https://github.com/claremacrae/talks/blob/main/HowTos/Set_up_Code_Coverage_on_Windows.md)
* Projector plugin
    * Install the Projector plugin
    * Restart CLion
    * Open Projector -> Start Remote Access to IDE
        * Change the port to 80 - instructions below show it as unchanged, 8887
        * Turn off "Require connection confirmation"
    * Add a Firewall rule to allow through incoming connections
        * Control Panel\System and Security\Windows Defender Firewall
        * -> Advanced settings
        * Right-click on "Inbound Rules" -> New Rule...
            * Rule type: Program
            * "This program path:" - paste in CLion path - without the quotes
                * To get CLion path, Right-click on in it task bar, then right-click on right-click on exe, then Properties - and copy the Target
                * Next
            * Allow the connection
            * Keep clicking Next until you reach Name - call it "Projector"
            * Finish
    * Open the port number on Amazon
        * Go the "Security Groups" for the instance
        * Add an Inbound Rule
            * Type = Custom TCP
            * Protocol = TCP
            * Port Range = the Port in the Projector settings (e.g. 8887 or 80)
            * Source = 0.0.0.0/0 (all)
            * Name = Projector
    * Get the actual public IP address
        * On the VM, in a web browser, search for "what is my IP address"
        * In the Project settings, ignore the URLs in the invitation links
        * Substitute in the visible URL
    * Try to find a way to serve the URL via "Let's Encrypt" or similar

## Visual Studio

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
    * Tools -> Options -> Text Editor -> Markdown
        * Turn on soft wrap
        * Turn on line numbers
        * Use bar mode for vertical preview
        * Advanced: Turn off "Enable preview window"
    * Only the course.md file is open in Visual Studio

## Web tools

* Log in to Microsoft 365 account to view slides
    * Add Slides to Chrome bookmarks bar
* Make Chrome the default browser
* Log in to accounts
    * MindMup - with a non-admin account?

## Remote Access

Do one of:
* Run Any Desk
    * Enable unattended access
    * Note the machine ID and unattended access password in the course google doc  
* Log in to Teams

## Final prep

* Create a branch for the course
* Launch VM
* Run AnyDesk
