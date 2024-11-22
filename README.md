# QT_project_2022
## Objective
Create an app that can load a Spotify top dataset and implement some filters for convenient music search.
## Structure:
- ### UIs:
  * addrowdialog.ui
  * aboutus.ui
  * mainwindow.ui
- ### Header Files:
  * addrowdialog.h
  * aboutus.h
  * mainwindow.h
  * tablebighw.h
- ### Source Files:
  * main.cpp
  * mainwindow.cpp
  * tablebighw.cpp
  * aboutus.cpp
  * addrowdialog.cpp

## Features:
- Load File function – read information from given .csv file and then this data is represented using QAbstractTableModel
- Save File
- Info menu – contains student id and Logo
  * Logo is drawn by QPainter
- TableView:
  * Sorting by artist, song name, genre, duration and popularity rate (parameter can be chosen by ComboBox)
  * Search-function implemented with QLineEdit ( user can type there any song name )
  * Showing all information about certain songs ( user can click on any cell and the  app will show all the parameters in groupbox located near TableView)
  * Filtering by several “Genre” parameters (Pop, Hip-hop, Dance, Rock) using CheckBoxes
  * Ability to edit any cell by double click
  * Adding new rows to tabelView (after click on the button, a special UI opens, in which the user can write all the data for a new row, after being filled with data, the row is then added by click on Add button)

## Results
As a result of the work the application for the music dataset is developed, so it can be improved in the future by implementing new functions for diversifying the range of functions ( for instance, adding tracks to the user’s playlist) and making the interface more user-friendly.
