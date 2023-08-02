#pragma once

#include <QtWidgets/QMainWindow>
#include "HomeScreen.h"

class QPushButton;
class QCheckBox;
class QSpinBox;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QWidget;

class PasswordGenerator : public QMainWindow
{
    Q_OBJECT

public:
    PasswordGenerator(QWidget *parent = nullptr);
    ~PasswordGenerator();

private:
    HomeScreen* m_homeScreen;
};
