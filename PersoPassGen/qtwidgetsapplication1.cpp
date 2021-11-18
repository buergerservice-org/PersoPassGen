#include "qtwidgetsapplication1.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QClipboard>
#include <QTableWidget>
#include <QStandardPaths>

#include "stdafx.h"
//#include <string>
#include <stdint.h>
#include <sstream>



std::string generateUpperCase(int n)
{
    std::string number = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string x = "";
    int random = 0;
    
    for (int i = 0; i < n; i++)
    {
        random = rand() % number.size();
        x.append(number, random, 1);
    }
    return x;
}


std::string generateSpecialSign(int n, std::string s)
{
    std::string sc = s;
    std::string x = "";
    int random = 0;
    
    for (int i = 0; i < n; i++)
    {
        random = rand() % sc.size();
        x.append(sc, random, 1);
    }
    return x;
}


inline unsigned int stoui(const std::string& s)
{
    std::istringstream reader(s);
    unsigned int val = 0;
    reader >> val;
    return val;
}



QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    QMessageBox msgBox;
    ui.setupUi(this);
    defaultnumberChars = 66;

    //Buttons
    connect(ui.GenButton, &QPushButton::clicked, this, &QtWidgetsApplication1::on_GenButton_clicked);
    connect(ui.InputButton, &QPushButton::clicked, this, &QtWidgetsApplication1::on_InputButton_clicked);
    connect(ui.DeleteButton, &QPushButton::clicked, this, &QtWidgetsApplication1::on_DeleteButton_clicked);
    connect(ui.NumCharButton, &QPushButton::clicked, this, &QtWidgetsApplication1::on_NumCharButton_clicked);
    connect(ui.SpecCharButton, &QPushButton::clicked, this, &QtWidgetsApplication1::on_SpecCharButton_clicked);

    //Menu
    connect(ui.actionOeffnen, &QAction::triggered, this, &QtWidgetsApplication1::on_MenuOeffnen_triggered);
    connect(ui.actionSpeichern, &QAction::triggered, this, &QtWidgetsApplication1::on_MenuSpeichern_triggered);
    connect(ui.actionHilfe, &QAction::triggered, this, &QtWidgetsApplication1::on_MenuHilfe_triggered);
    connect(ui.actionUeber, &QAction::triggered, this, &QtWidgetsApplication1::on_MenuUeber_triggered);
    connect(ui.actionZertifikat, &QAction::triggered, this, &QtWidgetsApplication1::on_MenuZertifikat_triggered);

 
    ui.tableWidget->setColumnWidth(0, 210);
    ui.tableWidget->setColumnWidth(1, 70);
    ui.tableWidget->setColumnWidth(2, 110);

    //read config.txt
    if (QSysInfo::windowsVersion() == QSysInfo::WV_WINDOWS10) {
        setStyleSheet(
            "QHeaderView::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "padding:4px;"
            "}"
            "QTableCornerButton::section{"
            "border-top:0px solid #D8D8D8;"
            "border-left:0px solid #D8D8D8;"
            "border-right:1px solid #D8D8D8;"
            "border-bottom: 1px solid #D8D8D8;"
            "background-color:white;"
            "}");
    }

    QString appconfigpath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir dir(appconfigpath);
    QDir::setCurrent(appconfigpath);
    QFile file("config.txt");
    if (QFileInfo(file).exists())
    {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("ERROR");
            msgBox.setText("ERROR - could not open config.txt.\n");
            msgBox.exec();
            return;
        }
        int rc = 0;
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList splitline = line.split(';');
            //numberChars = splitline[0].toInt();
            //specialSigns = splitline[1].toStdString();
            //datab.append(splitline);
            ui.tableWidget->insertRow(rc);
            ui.tableWidget->setItem(rc, 0, new QTableWidgetItem(splitline[0]));
            ui.tableWidget->setItem(rc, 1, new QTableWidgetItem(splitline[1]));
            ui.tableWidget->setItem(rc, 2, new QTableWidgetItem(splitline[2]));
            rc++;
        }
        //ui.tableWidget->repaint();
    }
    else
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Information");
        msgBox.setText("config.txt does not exist.\n");
        msgBox.exec();
    }

    //tableWidget
    //connect(ui.tableWidget, &QTableWidget::cellChanged, this, &QtWidgetsApplication1::on_tablecellchanged);

}

void QtWidgetsApplication1::on_GenButton_clicked()
{
    //ui.Label1->setText("clicked");
    QString curitem;
    QString wfoutput;
    QString PIN;
    std::string outputstring;
    std::string addstr;
    QMessageBox msgBox;
    QInputDialog diaBox;
    bool ok;
    
    
    if (ui.tableWidget->selectedItems().size() == 0)
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("Error - no entry selected");
        msgBox.exec();
        return;
    }

    outputstring = w.getkeypad();
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("ERROR");
    if (outputstring == "e1")
    {
        msgBox.setText("ERROR - please check AusweisApp2, cardreader and Personalausweis!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e2")
    {
        msgBox.setText("ERROR - please check your Personalausweis!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e3")
    {
        msgBox.setText("ERROR - please check your cardreader!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e4")
    {
        msgBox.setText("ERROR - AusweisApp2-version less than 1.22.* please update!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e5")
    {
        msgBox.setText("Warning - retryCounter of Perso <3, please start a selfauthentication direct with AusweisApp2!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e7")
    {
        msgBox.setText("ERROR - no cardreader found!");
        msgBox.exec();
        return;
    }

    if (outputstring == "false")
    {
        PIN = diaBox.getText(0, "PIN", "Bitte PIN eingeben:", QLineEdit::Password, "", &ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        if (PIN == "")
        {
            msgBox.setText("ERROR - PIN is empty.");
            msgBox.exec();
            return;
        }
        if (PIN.length() < 6)
        {
            msgBox.setText("ERROR - PIN is too short.");
            msgBox.exec();
            return;
        }
        if (PIN.length() > 6)
        {
            msgBox.setText("ERROR - PIN is too long.");
            msgBox.exec();
            return;
        }
    }
    else
    {
        PIN = "123456";
    }

    msgBox.setWindowModality(Qt::NonModal);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Information");
    msgBox.setText("selfauthentication is running, please wait...\n(this window closes self-acting)");
    QCoreApplication::processEvents();
    msgBox.show();
    QCoreApplication::processEvents();

    //QMessageBox* msgBox1 = new QMessageBox;
    //msgBox1->setText("selfauthentication is running, please wait...\n(this window closes self-acting)");
    //msgBox1->setWindowModality(Qt::NonModal);
    //QCoreApplication::processEvents();
    //msgBox1->show();
    //QCoreApplication::processEvents();


    outputstring= w.startworkflow(PIN.toUtf8().constData());
    PIN = "000000";
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("ERROR");
    if (outputstring == "e1")
    {
        msgBox.setText("ERROR - please check AusweisApp2, cardreader and Personalausweis!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e2")
    {
        msgBox.setText("ERROR - please check your Personalausweis!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e3")
    {
        msgBox.setText("ERROR - please check your cardreader!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e4")
    {
        msgBox.setText("ERROR - AusweisApp2-version less than 1.22.* please update!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e5")
    {
        msgBox.setText("Warning - retryCounter of Perso <3, please start a selfauthentication direct with AusweisApp2!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e7")
    {
        msgBox.setText("ERROR - no cardreader found!");
        msgBox.exec();
        return;
    }


    //generate password
    int rc = ui.tableWidget->currentRow();
    int accnumchars = ui.tableWidget->item(rc, 1)->text().toInt();
    std::string sch = ui.tableWidget->item(rc, 2)->text().QString::toStdString();

    //------------
    //msgBox.setText("accnumchars: "+QString::number(accnumchars) + "   specialchars: " + QString::fromStdString(sch));
    //msgBox.exec();


    addstr = "";
    curitem = ui.tableWidget->currentItem()->text();
    addstr = curitem.toUtf8().constData() + outputstring + std::to_string(accnumchars);
    outputstring = w.sha256(addstr);
    srand(stoui(outputstring));

    //------------
    //msgBox.setText(QString::fromUtf8(outputstring.c_str())+" "+QString::number(QString::fromUtf8(outputstring.c_str()).length()));
    //msgBox.exec();


    outputstring = generateUpperCase(1) + generateSpecialSign(1, sch) + outputstring.substr(0, accnumchars-2);
    wfoutput = QString::fromUtf8(outputstring.c_str());
    ui.lineEdit->setText(wfoutput);

    //------------
    //msgBox.setText(wfoutput+" "+QString::number(wfoutput.length()));
    //msgBox.exec();


    QClipboard* clipboard = QGuiApplication::clipboard();
    clipboard->setText(wfoutput);

    outputstring = w.GivenNames;
    outputstring = outputstring.append(", for your information the data from Personalausweis:\n\n\n");

    outputstring = outputstring.append("PersonalData read (for your information):\n\n");
    outputstring = outputstring.append("   AcademicTitle: " + w.AcademicTitle + "\n");
    outputstring = outputstring.append("   ArtisticName: " + w.ArtisticName + "\n");
    outputstring = outputstring.append("   BirthName: " + w.BirthName + "\n");
    outputstring = outputstring.append("   DateOfBirth: " + w.DateOfBirth + "\n");
    outputstring = outputstring.append("   DocumentType: " + w.DocumentType + "\n");
    outputstring = outputstring.append("   FamilyNames: " + w.FamilyNames + "\n");
    outputstring = outputstring.append("   GivenNames: " + w.GivenNames + "\n");
    outputstring = outputstring.append("   IssuingState: " + w.IssuingState + "\n");
    outputstring = outputstring.append("   Nationality: " + w.Nationality + "\n");
    outputstring = outputstring.append("      PlaceOfBirth: " + w.PlaceOfBirth + "\n");
    outputstring = outputstring.append("   PlaceOfResidence - StructuredPlace:\n");
    outputstring = outputstring.append("      City: " + w.City + "\n");
    outputstring = outputstring.append("      Country: " + w.Country + "\n");
    outputstring = outputstring.append("      Street: " + w.Street + "\n");
    outputstring = outputstring.append("      ZipCode: " + w.ZipCode + "\n");

    msgBox.setWindowTitle("Information");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(QString::fromUtf8(outputstring.c_str()));
    msgBox.exec();

    
    std::string su = "000000000000000000";
    w.personalStyledString = su;
    w.AcademicTitle = su;
    w.ArtisticName = su;
    w.BirthName = su;
    w.DateOfBirth = su;
    w.DocumentType = su;
    w.FamilyNames = su;
    w.GivenNames = su;
    w.IssuingState = su;
    w.Nationality = su;
    w.PlaceOfBirth = su;
    w.City = su;
    w.Country = su;
    w.Street = su;
    w.ZipCode = su;


}


void QtWidgetsApplication1::on_InputButton_clicked()
{
    QMessageBox msgBox;
    bool ok;

    QString itext = QInputDialog::getText(this,
        tr(" "),
        tr("Neuer Eintrag:"),
        QLineEdit::Normal,
        "",
        &ok);

    if (ok && !itext.isEmpty())
    {
        //set username in ui
        //ui.tableWidget->addItem(itext);
        int rc = ui.tableWidget->rowCount();

        //------------
        //msgBox.setText("rowCount: "+QString::number(rc));
        //msgBox.exec();

        ui.tableWidget->insertRow(rc);
        ui.tableWidget->setItem(rc, 0, new QTableWidgetItem(itext));
        ui.tableWidget->setItem(rc, 1, new QTableWidgetItem(QString::number(defaultnumberChars)));
        ui.tableWidget->setItem(rc, 2, new QTableWidgetItem(QString::fromStdString(defaultspecialSigns)));
        //ui->listWidget->repaint();
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("ERROR - Eingabedaten nicht vollstaendig.");
        msgBox.exec();
        return;
    }
}


void QtWidgetsApplication1::on_DeleteButton_clicked()
{
    QMessageBox msgBox;

    if (ui.tableWidget->selectedItems().size() == 0)
    {
        msgBox.setWindowTitle("ERROR");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("ERROR - no entry selected");
        msgBox.exec();
        return;
    }

    int itemselected = ui.tableWidget->currentRow();
    ui.tableWidget->removeRow(itemselected);
}


void QtWidgetsApplication1::on_MenuOeffnen_triggered()
{
    QMessageBox msgBox;
    QMessageBox::StandardButton reply;
    //if (ui.tableWidget->count() > 0)
    if (ui.tableWidget->rowCount()>0)
    {
        reply = msgBox.question(this, "Anhaengen", "Es sind bereits Eintraege vorhanden, Daten anhaengen?",
            QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
    }
    
    QFile file("config.txt");
    if (QFileInfo(file).exists())
    {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("ERROR");
            msgBox.setText("ERROR - could not open config.txt.\n");
            msgBox.exec();
            return;
        }
        int rc = ui.tableWidget->rowCount();
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList splitline = line.split(';');
            //numberChars = splitline[0].toInt();
            //specialSigns = splitline[1].toStdString();
            //datab.append(splitline);
            ui.tableWidget->insertRow(rc);
            ui.tableWidget->setItem(rc, 0, new QTableWidgetItem(splitline[0]));
            ui.tableWidget->setItem(rc, 1, new QTableWidgetItem(splitline[1]));
            ui.tableWidget->setItem(rc, 2, new QTableWidgetItem(splitline[2]));
            rc++;
        }
    }
}


void QtWidgetsApplication1::on_MenuSpeichern_triggered()
{
    QMessageBox msgBox;
    //QString fileName = QFileDialog::getSaveFileName(this,
    //    tr("Speichern Tabelle"), "",
    //    tr("ListTabelle (*.txt)"));
    //if (!fileName.endsWith(".txt"))
    //{
    //    fileName = fileName + ".txt";
    //}
    QString appconfigpath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir dir(appconfigpath);
    if (!dir.exists())
        dir.mkpath(appconfigpath);
    //-----------------
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Information");
    msgBox.setText("config.txt will be stored in: "+appconfigpath);
    msgBox.exec();

    QDir::setCurrent(appconfigpath);
    QFile file("config.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    //for (int i = 0; i < ui.tableWidget->count(); i++) {
    for(int i=0; i < ui.tableWidget->rowCount(); i++) {
        out << ui.tableWidget->item(i,0)->text() << ";" << ui.tableWidget->item(i, 1)->text() <<";" << ui.tableWidget->item(i, 2)->text() << "\n";
    }

}


void QtWidgetsApplication1::on_MenuHilfe_triggered()
{
    QMessageBox msgBox;
    QString Info;

    Info = "PersoPassGen\n\nHier koennen Sie mittels der Selbstauskunft des deutschen Personalausweises Passwoerter erstellen.\n\nBitte stellen Sie sicher, dass die AusweisApp2 gestartet ist,\nein Kartenleser angeschlossen und Ihr Personalausweis aufgelegt ist.\n\nWaehlen Sie im Listenfeld einen Eintrag.\nWenn Sie dann auf <Generiere> klicken wird es erstellt.\nDie gelesenen Ausweisdaten werden Ihnen zur Info angezeigt.\nDas Passwort koennen Sie dann unten dem Feld <Generiertes Passwort> entnehmen.\n";
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Information");
    msgBox.setText(Info);
    msgBox.exec();
}



void QtWidgetsApplication1::on_MenuUeber_triggered()
{
    QMessageBox msgBox;
    QString Info;

    Info = "PersoPassGen\nVersion 0.2\nCopyright 2021 buergerservice.org e.V. <KeePerso@buergerservice.org>\nlicense: GPL-3.0\n";
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Information");
    msgBox.setText(Info);
    msgBox.exec();
}


void QtWidgetsApplication1::on_MenuZertifikat_triggered()
{
    QMessageBox msgBox;
    QString Info;
    std::string outputstring;

    outputstring = w.getcertificate();
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("ERROR");
    if (outputstring == "e1")
    {
        msgBox.setText("ERROR - please check AusweisApp2, cardreader and Personalausweis!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e2")
    {
        msgBox.setText("ERROR - please check your Personalausweis!");
        msgBox.exec();
        return;
    }
    else if (outputstring == "e3")
    {
        msgBox.setText("ERROR - please check your cardreader!");
        msgBox.exec();
        return;
    }
    std::string ap = "information about the certificate you are using to identify at provider:\n\n";
    ap.append("description: \n");
    ap.append("   issuerName: " + w.issuerName + "\n");
    ap.append("   issuerUrl: " + w.issuerUrl + "\n");
    ap.append("   purpose: " + w.purpose + "\n");
    ap.append("   subjectName: " + w.subjectName + "\n");
    ap.append("   subjectUrl: " + w.subjectUrl + "\n\n");
    ap.append("termsOfUsage:\n" + w.termsOfUsage + "\n\n");
    ap.append("validity: \n");
    ap.append("   effectiveDate: " + w.effectiveDate + "\n");
    ap.append("   expirationDate: " + w.expirationDate + "\n");
    Info = QString::fromUtf8(ap.c_str());
    
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Information");
    msgBox.setText(Info);
    msgBox.exec();
}


void QtWidgetsApplication1::on_NumCharButton_clicked()
{
    QMessageBox msgBox;
    QString Info;
    bool ok;


    if (ui.tableWidget->selectedItems().size() == 0)
    {
        msgBox.setWindowTitle("ERROR");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("ERROR - no entry selected");
        msgBox.exec();
        return;
    }

    int iInput = QInputDialog::getInt(this,
        tr(" "),
        tr("Anzahl Zeichen aendern:"),
        defaultnumberChars, 6, 66, 1,
        &ok);

    if (ok)
    {
        int itemselected = ui.tableWidget->currentRow();
        ui.tableWidget->setItem(itemselected, 1, new QTableWidgetItem(QString::number(iInput)));

        /*
        QFile file("config.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        //for (int i = 0; i < ui.tableWidget->count(); i++) {
        for (int i = 0; i < ui.tableWidget->rowCount(); i++) {
            out << ui.tableWidget->item(i, 0)->text() << ";" << ui.tableWidget->item(i, 1)->text() << ";" << ui.tableWidget->item(i, 2)->text() << "\n";
        }
        */
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("ERROR - no input.");
        msgBox.exec();
        return;
    };
}


void QtWidgetsApplication1::on_SpecCharButton_clicked()
{
    QMessageBox msgBox;
    QString Info;
    bool ok;


    if (ui.tableWidget->selectedItems().size() == 0)
    {
        msgBox.setWindowTitle("ERROR");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("ERROR - no entry selected");
        msgBox.exec();
        return;
    }

    QString itext = QInputDialog::getText(this,
        tr(" "),
        tr("Aendere Sonderzeichen:"),
        QLineEdit::Normal,
        QString::fromStdString(defaultspecialSigns),
        &ok);

    if (ok && !itext.isEmpty())
    {
        int itemselected = ui.tableWidget->currentRow();
        ui.tableWidget->setItem(itemselected, 2, new QTableWidgetItem(itext));

        /*
        QFile file("config.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        //for (int i = 0; i < ui.tableWidget->count(); i++) {
        for (int i = 0; i < ui.tableWidget->rowCount(); i++) {
            out << ui.tableWidget->item(i, 0)->text() << ";" << ui.tableWidget->item(i, 1)->text() << ";" << ui.tableWidget->item(i, 2)->text() << "\n";
        }
        */
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("ERROR - no input.");
        msgBox.exec();
        return;
    }
}

//void QtWidgetsApplication1::on_tablecellchanged()
//{
    //QFile file("config.txt");
    //if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    //    return;

    //QTextStream out(&file);
    //for (int i = 0; i < ui.tableWidget->count(); i++) {
    //for (int i = 0; i < ui.tableWidget->rowCount(); i++) {
    //    out << ui.tableWidget->item(i, 0)->text() << ";" << ui.tableWidget->item(i, 1)->text() << ";" << ui.tableWidget->item(i, 2)->text() << "\n";
    //}
//}