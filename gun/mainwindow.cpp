#include "mainWindow.h"

#include "ui_mainwindow.h"
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "gun.h"
#include "bullet.h"

using namespace gun;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, mUi(new Ui::MainWindow)
{
	mUi->setupUi(this);
	mScene = new QGraphicsScene;
	mUi->graphicsView->setScene(mScene);
	mUi->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
	mGun = new Gun(mScene
		, mUi->powerSlider
		, mUi->angleSlider
		, mUi->powerLabel
		, mUi->angleLabel);
	mBullet = new Bullet(mScene
		, mGun
		, mUi->fireButton);
}

MainWindow::~MainWindow()
{
	delete mGun;
	delete mBullet;
	delete mScene;
	delete mUi;
}
