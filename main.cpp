#include <SFML/Graphics.hpp>

struct Pieces
{
  sf::CircleShape piece;
  sf::Color color = sf::Color::White;
  bool set = false;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(350, 350), "Connect 4");
    Pieces board[7][6];
    Pieces currentPiece;
    currentPiece.color = sf::Color::Red;
    currentPiece.piece.setRadius(20);
    currentPiece.piece.setPosition(sf::Vector2f((window.getSize().x / 2) - 20, window.getSize().y - 50));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
              if (event.mouseButton.button == sf::Mouse::Left) {
                for (int i = 0; i < 7; i++) {
                  if (board[i][0].piece.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    for (int j = 5; j > 0; j--) {
                      if (!board[i][j].set) {
                        board[i][j].set = true;
                        if (currentPiece.color == sf::Color::Red) {
                          currentPiece.color = sf::Color::Yellow;
                          board[i][j].color = sf::Color::Red;
                        }
                        else {
                          currentPiece.color = sf::Color::Red;
                          board[i][j].color = sf::Color::Yellow;
                        }
                        break;
                      }
                    }
                  }
                }
              }
            }
        }
        currentPiece.piece.setFillColor(currentPiece.color);
        window.clear();
        window.draw(currentPiece.piece);
        for (int i = 0; i < 7; i++) {
          for (int j = 0; j < 6; j++) {
            board[i][j].piece.setRadius(20);
            board[i][j].piece.setFillColor(board[i][j].color);
            board[i][j].piece.setPosition(sf::Vector2f((i * 50) + 5, (j * 50) + 5));
            window.draw(board[i][j].piece);
          }
        }
        window.display();
    }
}
