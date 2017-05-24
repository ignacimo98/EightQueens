//
// Created by jimena on 09/05/17.
//
#include <zconf.h>
#include <fstream>
#include "GUIManager.h"

GUIManager::GUIManager() {
    std::cout<<"GUI Created"<<std::endl;

    backgroundTexture.loadFromFile("Resources/Background1.jpeg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1400,800));

    miniQueenTexture.loadFromFile("Resources/miniqueen.png");
    miniQueenJaqueTexture.loadFromFile("Resources/miniQueenJaque.png");


    chessBoardTexture.loadFromFile("Resources/ChessBoard.jpg");
    chessBoardSprite.setTexture(chessBoardTexture);
    chessBoardSprite.setPosition(500, 160);

    cardsFont.loadFromFile("Resources/CardsFont.TTF");
    titleLabel.setFont(cardsFont);
    titleLabel.setCharacterSize(60);
    titleLabel.setString("The Eight Queens' Problem");
    titleLabel.setPosition(50,50);
    titleLabel.setStyle(sf::Text::Italic);

    createQueens();
}


int GUIManager::run(sf::RenderWindow &window) {
    solve8Queens(window);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                int i, j;
                for (i = 0; i < 8; i++){
                    queens[i].setPosition(-80,-80);
                    for (j = 0; j < 8; j++){
                        board[i][j] =0;
                    }
                }
                return 0;
            }
        }
    }
    return 4;
}

void GUIManager::moveQueens(sf::RenderWindow &window){
    for(int i = 0; i<8; i++){
        queens[i].setPosition(-80,-80);
    }
    drawQueens(window);
    int counter =0;
    for(int i = 0; i<8;i++){
        for(int j = 0; j<8;j++){
            if(board[i][j] == 1){
                queens[counter].setPosition(j*74+500, i*74+160);
                counter++;
                break;
            }
        }
    }
    drawQueens(window);
}

bool GUIManager::isSafe(int board[8][8], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j>= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < 8 && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

void printBoard(int board[8][8]){
    int i, j;

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << std:: endl;
    }
}

void GUIManager::writeBoard(){
    std::ofstream out;
    out.open("Movements.txt", std::ios::app);
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            out << board[i][j] << " "; }
        out << std:: endl;
    }
    out << std::endl;

}

bool GUIManager::solve8QueensAux(int board[8][8], int col, sf::RenderWindow &window) {
    if (col >= 8)
        return true;
    int i;
    for (i = 0; i < 8; i++){
        if (isSafe(board, i, col)){
            board[i][col] = 1;
            printBoard(board);
            writeBoard();
            moveQueens(window);
            usleep(500000);
            std::cout <<"nuevo movimiento"<<std::endl;
            if (solve8QueensAux(board, col + 1, window))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}


void GUIManager::solve8Queens(sf::RenderWindow &window){

    if (solve8QueensAux(board, 0, window) == false){
        std::cout << "There's no solution";
    }

}

void GUIManager::createQueens() {
    for(int i = 0; i<8; i++){
        sf::Sprite miniQueenSprite;
        miniQueenSprite.setTexture(miniQueenTexture);
        miniQueenSprite.setPosition(-80,-80);
        queens.push_back(miniQueenSprite);
    }
}

void GUIManager::drawQueens(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(chessBoardSprite);
    window.draw(titleLabel);

    for(int i = 0; i<queens.size(); i++){
        window.draw(queens[i]);
    }

    window.display();
}

GUIManager::~GUIManager() {

}

void GUIManager::checkJaque() {
    for(int i=0; i<8;i++){
        for(int j=0; j<8; j++){
            if(i!= j) {
                ///Chequea diagonal
                if (abs((int)queens[i].getPosition().y - queens[j].getPosition().y) == abs((int)(queens[i].getPosition().x - queens[j].getPosition().x))){
                    queens[i].setTexture(miniQueenJaqueTexture);
                    queens[j].setTexture(miniQueenJaqueTexture);
                }
            }
        }
    }
}
