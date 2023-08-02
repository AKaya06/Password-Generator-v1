#pragma once

#include <QtWidgets/qwidget.h>

class QPushButton;
class QCheckBox;
class QSpinBox;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QWidget;
class QLabel;

class HomeScreen : public QWidget {
    Q_OBJECT

public:
    HomeScreen();
    ~HomeScreen();

private slots:
    void createPassword(void);
    void hidePassword(bool _checked);

    void buttonHandler();

private:
    QVBoxLayout* m_mainLayout;

    QVBoxLayout* m_outputLayout;
    QWidget* m_outputLayoutW;
    QLineEdit* m_output;

    QVBoxLayout* m_checkboxLayout;
    QWidget* m_checkboxLayoutW;
    QCheckBox* m_uppercaseCheck;
    QCheckBox* m_lowercaseCheck;
    QCheckBox* m_numberCheck;
    QCheckBox* m_specialCheck;

    QVBoxLayout* m_spinboxLayout;
    QWidget* m_spinboxLayoutW;
    QSpinBox* m_characterCount;
    QLabel* m_characterCountLabel;

    QHBoxLayout* m_buttonLayout;
    QWidget* m_buttonLayoutW;
    QPushButton* m_createButton;
    QCheckBox* m_hideButton;

    QString m_password;
};