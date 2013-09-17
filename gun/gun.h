#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>

// Class which represents a gun
class Gun : public QObject {
    Q_OBJECT
public:
    explicit Gun(QObject *parent = 0);
    
    Gun(QGraphicsScene *scene
        , QSlider *powerSlider
        , QSlider *angleSlider
        , QLabel *pLabel
        , QLabel *aLabel);
public slots:
    // Method which is needed to set a rotation angle
    void setAngle(int angle);

    // Method which is needed to set a power of the shot
    void setPower(int value);

    // Function which returns angle
    int rotationAngle();

    // Function which returns power level
    int powerLevel();

private:
    // The gun itself
    QGraphicsRectItem *mBody;

    //Label which shows power of the shot
    QLabel *mPowerLabel;

    // Label which shows angle of the shot
    QLabel *mAngleLabel;

    // Rotation angle
    qreal mRotateAngle;

    // Power of the shot
    qreal mPower;
};
