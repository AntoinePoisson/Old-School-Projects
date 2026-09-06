# EPICTURE

## Depedencies
Project was build using IntelJ IDEA 2020.2 and Kotlin with gradle as build system.\
Epicture was built for Android SDK 28.

## File
### UI file
All the image and icon are in the drawable folder.\
All the layout for the application are in the layout folder. All the file must be name [type]\_[Activy/Fragment it belong to]\_[use]

### Kotlin file
#### Imgur folder
Contains all the necessay function and classe for calling imgur api

#### Login
The loading screen is composed of 2 parts.
When the user open the app it launch MainPage.kt which check if the user is already login, if the user isalready login it automaticaly redirect to the home page otherwise it stay on the MainPage. 
Login: when the user click on the login button it open a web view with iumgur website that redirect to the app when the user is login.

#### Home page
