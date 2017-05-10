//
// Created by jimena on 09/05/17.
//
#include "GUIManager.h"

GUIManager::GUIManager() {
    std::cout<<"GUI Created"<<std::endl;
    backgroundTexture.loadFromFile("Resources/Background1.jpeg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1400,800));

    miniQueenTexture.loadFromFile("Resources/miniqueen.png");


    chessBoardTexture.loadFromFile("Resources/ChessBoard.jpg");
    chessBoardSprite.setTexture(chessBoardTexture);
    chessBoardSprite.setPosition(500, 160);

    cardsFont.loadFromFile("Resources/CardsFont.TTF");
    titleLabel.setFont(cardsFont);
    titleLabel.setCharacterSize(60);
    titleLabel.setString("The Eight Queens' Problem");
    titleLabel.setPosition(50,50);
    titleLabel.setStyle(sf::Text::Italic);
}


int GUIManager::run(sf::RenderWindow &window) {
    solve8Queens();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return 0;
        }
        window.clear();



        window.draw(backgroundSprite);
        window.draw(chessBoardSprite);
        window.draw(titleLabel);

        if(move_made) {
            drawQueens(window);
            move_made = false;
        }
        for(int i = 0; i<queens.size(); i++){
            window.draw(queens[i]);
        }

        window.display();
    }
    return 4;
}

void GUIManager::drawQueens(sf::RenderWindow &window){
    for(int i = 0; i<8;i++){
        for(int j = 0; j<8;j++){
            if(board[i][j] == 1){
                sf::Sprite miniQueenSprite;
                std::cout<<"holi"<<std::endl;
                miniQueenSprite.setTexture(miniQueenTexture);
                miniQueenSprite.setPosition(j*74+500, i*74+160);
                queens.push_back(miniQueenSprite);
            }
        }
    }
}

bool isSafe(int board[8][8], int row, int col) {
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

bool solve8QueensAux(int board[8][8], int col) {
    if (col >= 8)
        return true;

    int i;

    for (i = 0; i < 8; i++){
        if (isSafe(board, i, col)){
            board[i][col] = 1;

            if (solve8QueensAux(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void GUIManager::solve8Queens(){

    if (solve8QueensAux(board, 0) == false){
        std::cout << "There's no solution";
    }

}
