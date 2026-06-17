#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include<iostream>

#include <cstdlib>  // for rand() and srand()
#include <ctime> 

#include "shape.h"
#include "I.h"
#include "O.h"
#include "L.h"
#include "J.h"
#include "S.h"
#include "Z.h"
#include "T.h"


using namespace std;

const int row = 20, col = 10;
const float blockSize = 40.f;
static int lines = 0;
static int levels = 1;
static int score = 0;
bool gameover = false; // Game over check
float defaultFallDelay = 1.0f; // Fall delay
bool linecomp = false; // ine completion check
bool level = false;
const int reql = 8;

using namespace sf;





class game 
{
    int mat[20][10] = { 0 };
   

public:

    int randm() 
    {
        return (rand() % 7) + 1;  // gives 1 to 7
    }

    void clearLines() 
    {
          int k = row - 1;
          for (int i = row - 1; i >= 0; i--) 
          {
              int count = 0;
              for (int j = 0; j < col; j++) 
              {
                  if (mat[i][j])
                      count++;


                  mat[k][j] = mat[i][j];
              }


              if (count < col) 
              {
                  linecomp = false;
                  k--;
              }

              else
              {
                  lines++;
                  linecomp = true;
                  score += 100;
              }


          }
          for (int i = k; i >= 0; i--) 
          {
              for (int j = 0; j < col; j++)
              {
                  mat[i][j] = 0;
              }
          }
    }
   


    void reset_g()
    {
        level = 1;
        lines = 0;
        score = 0;
        gameover = false;
       // defaultFallDelay = 1.f;



        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                mat[i][j] = 0;
            }
        }
    }


    void updateLevel(int linesCleared, float& defaultFallDelay, float& c_fallDelay, bool down_key, float fastFallDelay)
    {
        int pre = levels;
        levels = (linesCleared / reql) % 8 + 1;
       
       

        cout << "Lines Cleared: " << linesCleared << ", Level: " << levels << endl;

        // Update defaultFallDelay directly so it carries to the next round
        defaultFallDelay = 1.0f * pow(0.9f, levels - 1);

        c_fallDelay = down_key ? fastFallDelay : defaultFallDelay;

        if (levels == 8)
        {
            reset_g();
            
        }
        cout << "Default Fall Delay: " << defaultFallDelay << "s\n";
       // cout << "Current Fall Delay: " << c_fallDelay << "s\n";
         
        if (levels != pre)
        {
            level = true;
        }
        else
            level = false;

    }

    shape* createShape(int id) 
    {
        switch (id) {
        case 1:
            return new I();
        case 2:
            return new O();
        case 3:
            return new L();
        case 4:
            return new J();
        case 5:
            return new S();
        case 6:
            return new Z();
        case 7:
            return new T();
        }
    }


    void display()
    {

        srand(time(0)); // For random


        int randomShape,pre_sh;
        randomShape = randm();
        pre_sh = randomShape;



        sf::RenderWindow window(sf::VideoMode(800, 900), "Tetris Grid");

        RectangleShape sh;


        shape* o = createShape(randomShape);


        // Clock
        sf::Clock fallClock;

        // Seconds
        float c_fallDelay = defaultFallDelay; // Initialize with default value
        float fastFallDelay = 0.05f; // Seconds


        
        // Text part
        sf::Font font;
        if (!font.loadFromFile("Content/Tetris.ttf")) {
            cout << "Failed to load font\n";
            return;
        }

        sf::Text scoreText, levelText, linesClearedText;
        scoreText.setFont(font);
        levelText.setFont(font);
        linesClearedText.setFont(font);

        scoreText.setCharacterSize(40);
        levelText.setCharacterSize(40);
        linesClearedText.setCharacterSize(40);

        scoreText.setFillColor(sf::Color::White);
        levelText.setFillColor(sf::Color::White);
        linesClearedText.setFillColor(sf::Color::White);

        scoreText.setPosition(550.f, 100.f);      // Right side of the grid
        levelText.setPosition(550.f, 400.f);
        linesClearedText.setPosition(550.f, 600.f);

        // SOunds
        Music music;
        if (!music.openFromFile("Content/MenuTheme.wav")) 
        {
            cout << "Error loading music\n";
        }
        else
        {
            music.setVolume(50);
            music.setLoop(true); // Music repeats
            music.play();        // Start playing
        }

        SoundBuffer gameOverB;
        Sound gameOverS;

        if (!gameOverB.loadFromFile("Content/game_over.wav")) {
            cout << "Failed to load Game Over sound!\n";
        }
        else {
            gameOverS.setBuffer(gameOverB);
        }

        SoundBuffer levelUpB;
        Sound levelUpS;
        if (!levelUpB.loadFromFile("Content/level_up.wav")) {
            cout << "Failed to load level up sound\n";
        }
        levelUpS.setBuffer(levelUpB);
        levelUpS.setVolume(100);


        // Adjustment to the grid 
        float spacing = 3.f;
        float size = 45.f;
        sh.setSize(Vector2f(size - spacing, size - spacing));

        bool down_key = false;


        // Game loop
        while (window.isOpen()) 
        {

            if (o->lockTheShapeInTheGrid(mat)) 
            {
                // Lock the current shape
                o->setMainarray(mat); // Make changes to the main array (mat)
                clearLines();

                {
                    updateLevel(lines, defaultFallDelay, c_fallDelay,down_key,fastFallDelay);
                    if (level) {
                        levelUpS.play();
                    }
                   
                  
                }
                
                randomShape = randm();
                while (randomShape == pre_sh)// Checks to make sure same shapes doesnot arrive consectively
                {
                    randomShape = randm();
                }
                o = createShape(randomShape);// Generates and assign the new shape
                pre_sh = randomShape;

                if (!o->isgamecon(mat))// Check for game completion
                {
                    gameover = true;
                }

                

                o->updateCoordinates(); //updating coordinates accordingly
            }



            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                    window.close();

                if (!gameover&&e.type == Event::KeyPressed) 
                {
                    if (e.key.code == Keyboard::Left)
                    {
                        o->moveLeft(mat);
                    }
                    else if (e.key.code == Keyboard::Right) 
                    {
                        o->moveRight(mat);
                    }
                    else if (e.key.code == Keyboard::Down) 
                    {
                        down_key = true;
                    }
                    else if (e.key.code == Keyboard::Up) 
                    {
                        o->rotate(mat);
                    }
                }
                if (e.type == Event::KeyReleased)
                    if (e.key.code == Keyboard::Down)
                    {
                        down_key = false; // For increasing falling speed
                    }

            }


            c_fallDelay = down_key ? fastFallDelay : defaultFallDelay;   // Update c_fallDelay based on whether the down key is pressed

            if (!gameover&&fallClock.getElapsedTime().asSeconds() > c_fallDelay)
            { 

                o->moveDown(mat);
                fallClock.restart();
            }
        
            if (gameover) {

                music.stop();              
                gameOverS.play();

                // Font for Gameover screen
                Font font;
                if (!font.loadFromFile("Content/PressStart2P-Regular.ttf"))
                {
                    cout << "Failed to load font\n";
                }
                else 
                {
                    Text gameOverText("GAME OVER", font, 60);
                    gameOverText.setFillColor(Color::White);
                    gameOverText.setStyle(Text::Bold);
                    gameOverText.setPosition(120, 400); 

                    window.clear(Color::Black);

                    window.draw(gameOverText);
                    window.display();

                    sleep(seconds(5));  // Show Game Over for 3 seconds
                }

                window.close();  // Cleanly close the window after showing Game Over
                break;  // Exit the main game loop
            }


            window.clear(Color::Black);

            // Bonus task text
            scoreText.setString("Score: " + std::to_string(score));
            levelText.setString("Level: " + std::to_string(levels));
            linesClearedText.setString("Lines: " + std::to_string(lines));


            // Displaying Grid 
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 10; j++) 
                {
                    switch (mat[i][j]) // Disply the blocks accordingly
                    {
                    case 0:
                        sh.setFillColor(Color(100, 100, 100, 100));
                        break;
                    case 1:
                        sh.setFillColor(Color::Blue);
                        break;
                    case 2:
                        sh.setFillColor(Color::Yellow);
                        break;
                    case 3:
                        sh.setFillColor(Color::Green);
                        break;
                    case 4:
                        sh.setFillColor(Color(75, 0, 130));
                        break;
                    case 5:
                        sh.setFillColor(Color::Magenta);
                        break;
                    case 6:
                        sh.setFillColor(Color::Red);
                        break;
                    case 7:
                        sh.setFillColor(Color(255, 165, 0));
                        break;
                    }

                    sh.setPosition(j * size, i * size);
                    window.draw(sh);
                }
            }
            window.draw(scoreText);
            window.draw(levelText);
            window.draw(linesClearedText);
            o->Draw(window, size);// Displays the shape while falling down
            window.display();
        }

        // Deletion of th object
        delete o;
    }

   
};
