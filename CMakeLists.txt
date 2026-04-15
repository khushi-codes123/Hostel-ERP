 cmake_minimum_required(VERSION 3.16)

project(HostelERP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

qt_add_executable(HostelERP
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    addstudent.cpp
    addstudent.h
    addstudent.ui
    viewstudents.h viewstudents.cpp viewstudents.ui
    addfee.h addfee.cpp addfee.ui
    viewfee.h viewfee.cpp viewfee.ui
    addcomplaint.h addcomplaint.cpp addcomplaint.ui
    viewcomplaint.h viewcomplaint.cpp viewcomplaint.ui
    logindialog.h logindialog.cpp logindialog.ui
    forgotpassworddialog.h forgotpassworddialog.cpp forgotpassworddialog.ui
    addroom.h addroom.cpp addroom.ui
    viewroom.h viewroom.cpp viewroom.ui
)

target_link_libraries(HostelERP
    PRIVATE Qt6::Widgets Qt6::Sql
)
