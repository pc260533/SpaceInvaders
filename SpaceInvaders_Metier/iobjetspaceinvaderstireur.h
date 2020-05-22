#ifndef IOBJETSPACEINVADERSTIREUR_H
#define IOBJETSPACEINVADERSTIREUR_H



class IObjetSpaceInvadersTireur {

public:
    IObjetSpaceInvadersTireur();
    virtual ~IObjetSpaceInvadersTireur();
    virtual void tirer() = 0;

};

#endif // IOBJETSPACEINVADERSTIREUR_H
