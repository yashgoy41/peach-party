#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Board.h"
#include <string>
#include <list>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Actor;
class Player;
class StudentWorld : public GameWorld {
public:
    StudentWorld(std::string assetPath);
    ~StudentWorld(){};
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    Board getBoard() const{return bd;}
    Player* getPlayer(int playerNum) const;
    void addPlayers(){m_numPlayers++;}
    int getNumPlayers() const{return m_numPlayers;}
    int getBankCoins() const{return m_totalBankCoins;}
    void updateBankCoins(int value) {m_totalBankCoins += value;}
    void resetBankCoins() {m_totalBankCoins = 0;}
    void addDroppingSquare(int x, int y);
    bool hitWithVortex(int x, int y);
    void createNewVortex(int x, int y, int dir);

private:
    std::list<Actor*> actorList;
    int m_numPlayers;
    int m_totalBankCoins;
    Player* m_peach;
    Player* m_yoshi;
    Board bd;
    
};

#endif // STUDENTWORLD_H_
