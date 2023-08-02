#include "PasswordGenerator.h"

// QtWidgets
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qpushbutton.h>

PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QMainWindow(parent)
{
    m_homeScreen = new HomeScreen;
    setCentralWidget(m_homeScreen);
    setMaximumSize(300, 300);
    setMinimumSize(300, 300);
}

PasswordGenerator::~PasswordGenerator()
{}
