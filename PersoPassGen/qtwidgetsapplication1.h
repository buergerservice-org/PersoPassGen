#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtwidgetsapplication1.h"
#include <string>
#include "workflowLibrary.h"


class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);
    Ui::QtWidgetsApplication1Class ui;

    //Buttons
    void on_GenButton_clicked();
    void on_InputButton_clicked();
    void on_DeleteButton_clicked();
    void on_NumCharButton_clicked();
    void on_SpecCharButton_clicked();

    //Menu
    void on_MenuOeffnen_triggered();
    void on_MenuSpeichern_triggered();
    void on_MenuHilfe_triggered();
    void on_MenuUeber_triggered();
    void on_MenuZertifikat_triggered();
    
    //tableWidget
    //void on_tablecellchanged();


private:
    workflowLibrary::workflow w;
    int defaultnumberChars;
    std::string defaultspecialSigns = ")($!=~*-";
};
