#include "HomeScreen.h"

// QtWidgets
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qmessagebox.h>

// QtCore
#include <QtCore/qstring.h>

// std
#include <random>

HomeScreen::HomeScreen() {
    // Create Layouts
    m_mainLayout = new QVBoxLayout(this);

    m_outputLayoutW = new QWidget;
    m_outputLayout = new QVBoxLayout(m_outputLayoutW);

    m_checkboxLayoutW = new QWidget;
    m_checkboxLayout = new QVBoxLayout(m_checkboxLayoutW);

    m_spinboxLayoutW = new QWidget;
    m_spinboxLayout = new QVBoxLayout(m_spinboxLayoutW);

    m_buttonLayoutW = new QWidget;
    m_buttonLayout = new QHBoxLayout(m_buttonLayoutW);

    // Create Controls
    m_output = new QLineEdit;
    m_uppercaseCheck = new QCheckBox("Capitalized letter(s)");
    m_lowercaseCheck = new QCheckBox("Lowercase letter(s)");
    m_numberCheck = new QCheckBox("Number(s)");
    m_specialCheck = new QCheckBox("Special character(s)");
    m_characterCount = new QSpinBox;
    m_characterCountLabel = new QLabel("How many characters should the password have?");
    m_createButton = new QPushButton("Create");
    m_hideButton = new QCheckBox("Hide Password");

    // Setup Layout
    m_mainLayout->addWidget(m_outputLayoutW);
    m_mainLayout->addWidget(m_checkboxLayoutW);
    m_mainLayout->addWidget(m_spinboxLayoutW);
    m_mainLayout->addWidget(m_buttonLayoutW);

    m_outputLayout->addWidget(m_output);

    m_checkboxLayout->addWidget(m_lowercaseCheck);
    m_checkboxLayout->addWidget(m_uppercaseCheck);
    m_checkboxLayout->addWidget(m_numberCheck);
    m_checkboxLayout->addWidget(m_specialCheck);
    m_checkboxLayout->addStretch(1);
    m_checkboxLayout->addWidget(m_characterCountLabel);

    m_spinboxLayout->addWidget(m_characterCount);

    m_buttonLayout->addWidget(m_createButton);
    m_buttonLayout->addWidget(m_hideButton);

    // Setup Controls
    m_output->setReadOnly(true);
    m_characterCount->setMinimum(1);
    m_characterCount->setMaximum(1000); //Set Maximum because default is 99
    m_createButton->setEnabled(false);

    // Connect signals
    connect(m_createButton, &QPushButton::clicked, this, &HomeScreen::createPassword);
    connect(m_hideButton, &QCheckBox::clicked, this, &HomeScreen::hidePassword);
    connect(m_uppercaseCheck, &QCheckBox::clicked, this, &HomeScreen::buttonHandler);
    connect(m_lowercaseCheck, &QCheckBox::clicked, this, &HomeScreen::buttonHandler);
    connect(m_numberCheck, &QCheckBox::clicked, this, &HomeScreen::buttonHandler);
    connect(m_specialCheck, &QCheckBox::clicked, this, &HomeScreen::buttonHandler);
}

HomeScreen::~HomeScreen()
{}

void HomeScreen::createPassword(void) {
    QString uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString lowercaseLetters = uppercaseLetters.toLower();
    QString specialCharacters = ".,!$%&/()=?#_<>";
    QString numbers = "1234567890";

    QString finalLetters = "";

    bool upper = m_uppercaseCheck->isChecked();
    bool lower = m_lowercaseCheck->isChecked();
    bool number = m_numberCheck->isChecked();
    bool special = m_specialCheck->isChecked();

    if (upper)
        finalLetters.append(uppercaseLetters);
    
    if (lower)
        finalLetters.append(lowercaseLetters);

    if (number)
        finalLetters.append(numbers);

    if (special)
        finalLetters.append(specialCharacters);

    QString password = "";

    for (int i = 0; i < m_characterCount->value(); i++) {
        int randomNumber = rand() % finalLetters.size();
        password.append(finalLetters[randomNumber]);
    }
    m_password = password;
    m_output->setText(m_password);

    if (m_hideButton->isChecked()) {
        QString hiddenPW = "";
        for (int i = 0; i < m_characterCount->value(); i++)
            hiddenPW.append("*");

        m_output->setText(hiddenPW);
    }
}

void HomeScreen::hidePassword(bool _checked) {
    if (_checked && m_output->text() != "") {
        QString hiddenPW = "";
        for (int i = 0; i < m_characterCount->value(); i++)
            hiddenPW.append("*");

        m_output->setText(hiddenPW);
    }
    else {
        m_output->setText(m_password);
    }
}

void HomeScreen::buttonHandler() {
    bool upper = m_uppercaseCheck->isChecked();
    bool lower = m_lowercaseCheck->isChecked();
    bool number = m_numberCheck->isChecked();
    bool special = m_specialCheck->isChecked();

    if (upper ||
        lower ||
        number||
        special)
        m_createButton->setEnabled(true);
    else
        m_createButton->setEnabled(false);
}