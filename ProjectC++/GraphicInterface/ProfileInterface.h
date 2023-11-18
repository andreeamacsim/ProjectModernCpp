#pragma once

#include <QMainWindow>
#include "ui_ProfileInterface.h"

class ProfileInterface : public QMainWindow
{
	Q_OBJECT

public:
	ProfileInterface(QWidget *parent = nullptr);
	~ProfileInterface();

private:
	Ui::ProfileInterfaceClass ui;
};
