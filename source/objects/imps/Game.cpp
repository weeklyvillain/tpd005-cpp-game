#include "../headers/Game.h"
int Game::run(int player_amount){

    sf::RenderWindow window{sf::VideoMode(1900, 900), "Bubble Bobble", sf::Style::Titlebar | sf::Style::Close};
    window.setVerticalSyncEnabled(true);
    World world{window, 0.5};

    std::vector<std::string> lvls
    {"assets/levels/level1.lvl" ,
     "assets/levels/level2.lvl",
     "assets/levels/level3.lvl",
     "assets/levels/level4.lvl",
     "assets/levels/level5.lvl",
     "assets/levels/level6.lvl",
     "assets/levels/level7.lvl",
     "assets/levels/level8.lvl"
    };
    sf::Texture t{};
    sf::Sprite bkg{};
    if(t.loadFromFile("assets/background.png")){
        bkg.setTexture(t);
    }

    int level_index{0};
    Level(lvls.at(level_index), 80, 80, world, player_amount);

    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(16.7)};

    while (world.run){
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    world.run = false;
                    break;
                case sf::Event::KeyPressed:
                    world.on_Key_Press(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    world.on_Key_Release(event.key.code);
                    break;
                case sf::Event::Resized:
                    //world.MaintainAspectRatio();
                    break;
                default:
                    if (world.player1.quit){
                        window.close();
                        world.run = false;
                    }
                    break;
			}
        }

        //Vänta tills nästa bildruta innan du ritar
        auto frameDelay = clock.restart();
        window.clear(sf::Color::White);
        //Ritar ut bakgrunden
        window.draw(bkg);

        sf::Font font{};
        if (font.loadFromFile("assets/ScoreFont.ttf")){
            draw_new_item("HP: " + std::to_string(world.get_lives()),
                sf::Vector2f(1700, 100), font, window);
            draw_new_item("Score: " + std::to_string(world.get_score()),
                sf::Vector2f(1700, 150), font, window);
        }
        if(!world.player1.pause){
            //Om spelaren har pausat ska spelet inte uppdateras
            world.update_all(frameDelay);
        }else{
            draw_new_item("Paused",
                sf::Vector2f(1600/2, 900/2), font ,window);
        }
        world.render_all();
        if(!world.get_player()) {
            sf::Texture t{};
            sf::Sprite screen{};
            if(t.loadFromFile("assets/game_over.png")){
                screen.setTexture(t);
                window.draw(screen);
            }
        }

        if ( targetFrameDelay > frameDelay ){
            //Vänta bara om du verkligen behöver
            auto sleepTime = targetFrameDelay - frameDelay;
            sf::sleep(sleepTime);
        }

        if(world.win()) {
            //Change level
            world.clear();
            level_index++;
            Level(lvls.at(level_index), 80, 80, world, player_amount);
        }
        window.display();
        if(!world.get_player()){
            sf::sleep(sf::seconds(4));
            set_score(world);
            draw_new_item("What's your name?", sf::Vector2f(1600/2, 400), font, window);
            window.close();
            return 0;
        }
    }
}
void Game::run_lan(int player_amount){
	const unsigned short PORT = 8080;

    sf::TcpListener listener;
	listener.listen(PORT);
	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;


        sf::RenderWindow window{sf::VideoMode(1900, 900), "Bubble Bobble", sf::Style::Titlebar | sf::Style::Close};
        window.setVerticalSyncEnabled(true);
        World world{window, 0.5};

        std::vector<std::string> lvls
        {"assets/levels/level1.lvl" ,
         "assets/levels/level2.lvl",
         "assets/levels/level3.lvl",
         "assets/levels/level4.lvl",
         "assets/levels/level5.lvl",
         "assets/levels/level6.lvl",
         "assets/levels/level7.lvl",
         "assets/levels/level8.lvl"
        };
        sf::Texture t{};
        sf::Sprite bkg{};
        if(t.loadFromFile("assets/background.png")){
            bkg.setTexture(t);
        }

        int level_index{0};
        Level(lvls.at(level_index), 80, 80, world, player_amount);

        sf::Clock clock;
        sf::Time targetFrameDelay {sf::milliseconds(16.7)};

        while (world.run){
            sf::Event event;
            while (window.pollEvent(event)){
                switch (event.type) {
                    case sf::Event::Closed:
                        world.run = false;
                        break;
                    case sf::Event::KeyPressed:
                        world.on_Key_Press(event.key.code);
                        break;
                    case sf::Event::KeyReleased:
                        world.on_Key_Release(event.key.code);
                        break;
                    case sf::Event::Resized:
                        //world.MaintainAspectRatio();
                        break;
                    default:
                        if (world.player1.quit){
                            window.close();
                            world.run = false;
                        }
                        break;
    			}
            }
            world.send_packet(socket.getRemoteAddress(), PORT);
            world.receive_packet(PORT);
            //Vänta tills nästa bildruta innan du ritar
            auto frameDelay = clock.restart();
            window.clear(sf::Color::White);
            //Ritar ut bakgrunden
            window.draw(bkg);

            sf::Font font{};
            if (font.loadFromFile("assets/ScoreFont.ttf")){
                draw_new_item("HP: " + std::to_string(world.get_lives()),
                    sf::Vector2f(1700, 100), font, window);
                draw_new_item("Score: " + std::to_string(world.get_score()),
                    sf::Vector2f(1700, 150), font, window);
                draw_new_item("IP-adress: \n" +
                    sf::IpAddress::getLocalAddress().toString(),
                        sf::Vector2f(1700, 200), font, window);
            }
            if(!world.player1.pause){
                //Om spelaren har pausat ska spelet inte uppdateras
                world.update_all(frameDelay);
            }else{
                draw_new_item("Paused",
                    sf::Vector2f(1600/2, 900/2), font ,window);
            }
            world.render_all();
            if(!world.get_player()) {
                sf::Texture t{};
                sf::Sprite screen{};
                if(t.loadFromFile("assets/game_over.png")){
                    screen.setTexture(t);
                    window.draw(screen);
                }
            }

            if ( targetFrameDelay > frameDelay ){
                //Vänta bara om du verkligen behöver
                auto sleepTime = targetFrameDelay - frameDelay;
                sf::sleep(sleepTime);
            }

            if(world.win()) {
                //Change level
                world.clear();
                level_index++;
                Level(lvls.at(level_index), 80, 80, world, player_amount);
            }
            window.display();
            if(!world.get_player()){
                sf::sleep(sf::seconds(4));
                set_score(world);
                draw_new_item("What's your name?", sf::Vector2f(1600/2, 400), font, window);
                window.close();
            }
        }
}
void Game::join(std::string ipadress) {
    const unsigned short PORT = 8080;
	const sf::IpAddress IPADDRESS(ipadress);//change to suit your needs

	std::string msgSend;

	sf::TcpSocket socket;
	sf::Mutex globalMutex;

	sf::TcpListener listener;
	listener.listen(PORT);
	listener.accept(socket);
	socket.connect(IPADDRESS, PORT);
 sf::RenderWindow window{sf::VideoMode(1900, 900), "Bubble Bobble", sf::Style::Titlebar | sf::Style::Close};
    window.setVerticalSyncEnabled(true);
    World world{window, 0.5};

    std::vector<std::string> lvls
    {"assets/levels/level1.lvl" ,
     "assets/levels/level2.lvl",
     "assets/levels/level3.lvl",
     "assets/levels/level4.lvl",
     "assets/levels/level5.lvl",
     "assets/levels/level6.lvl",
     "assets/levels/level7.lvl",
     "assets/levels/level8.lvl"
    };
    sf::Texture t{};
    sf::Sprite bkg{};
    if(t.loadFromFile("assets/background.png")){
        bkg.setTexture(t);
    }
    int level_index{0};
    Level(lvls.at(level_index), 80, 80, world, 2);

    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(16.7)};

    while (world.run){
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    world.run = false;
                    break;
                case sf::Event::KeyPressed:
                    world.on_Key_Press(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    world.on_Key_Release(event.key.code);
                    break;
                case sf::Event::Resized:
                    //world.MaintainAspectRatio();
                    break;
                default:
                    if (world.player1.quit){
                        window.close();
                        world.run = false;
                    }
                    break;
			}
        }

        //Vänta tills nästa bildruta innan du ritar
        auto frameDelay = clock.restart();



    world.send_packet(IPADDRESS, PORT);
	world.receive_packet(PORT);

        window.clear(sf::Color::White);
        window.draw(bkg);
        if(!world.player1.pause){
            world.update_all(frameDelay);
        }
        world.render_all();
        if(!world.get_player()) {
            sf::Texture t{};
            sf::Sprite screen{};
            if(t.loadFromFile("assets/game_over.png")){
                screen.setTexture(t);
                window.draw(screen);
            }
        }
        sf::Font font{};
        sf::Text txt;
        sf::Text paused;
        if (font.loadFromFile("assets/ScoreFont.ttf"))
    	{
            txt.setString("HP: " + std::to_string(world.get_lives()));
            sf::FloatRect item = txt.getGlobalBounds();
        	txt.setPosition(sf::Vector2f((1600 / 2) + 850, 900 / 4));
    		txt.setFont(font);
        	txt.setColor(sf::Color::Red);
            window.draw(txt);

            item = txt.getGlobalBounds();
        	txt.setPosition(sf::Vector2f((1600 / 2) + 850, 900 / 3));
    		txt.setFont(font);
        	txt.setColor(sf::Color::Red);
        	txt.setString("Score: " + std::to_string(world.get_score()));
            window.draw(txt);

            txt.setString("IP-adress: \n" +
                sf::IpAddress::getLocalAddress().toString());
            item = txt.getGlobalBounds();
        	txt.setPosition(sf::Vector2f((1600 / 2) + 850, 900 / 2));
    		txt.setFont(font);
        	txt.setColor(sf::Color::Red);
            window.draw(txt);

            if(world.player1.pause){
                item = paused.getGlobalBounds();
                paused.setPosition(sf::Vector2f((1600 / 2) - (item.width / 2), (900 / 2) - (item.height / 2)));
                paused.setFont(font);
                paused.setColor(sf::Color::Red);
                paused.setString("PAUSED");
                window.draw(paused);
            }
        }

        if ( targetFrameDelay > frameDelay )
        {
            //Vänta bara om du verkligen behöver
            auto sleepTime = targetFrameDelay - frameDelay;
            sf::sleep(sleepTime);
        }

        if(world.win()) {
            world.clear();
        }
        window.display();
        if(!world.get_player()){
            sf::sleep(sf::seconds(4));
            //set_score(world);
            window.close();
        }
    }
}
void Game::draw_new_item(std::string const& s, sf::Vector2f const& v, sf::Font const& f, sf::RenderWindow& window){
    sf::Text new_item{};
    sf::FloatRect item = new_item.getGlobalBounds();
    new_item.setPosition(v);
    new_item.setFont(f);
    new_item.setColor(sf::Color::Red);
    new_item.setString(s);
    window.draw(new_item);
}

void Game::set_name(std::string n) {
    name = n;
};

void Game::set_score(World& w) {
    std::ifstream ifs{"assets/score"};
    std::vector<std::pair<std::string, int>> score_list;
    if(ifs.is_open()) {
        for( std::string line; getline( ifs, line ); )
        {
            size_t middle_index{line.find(' ')};
            std::string user{line.substr(0, middle_index)};
            int score{stoi(line.substr(middle_index))};
            score_list.push_back(std::make_pair(user, score));
        }
    }
    ifs.close();
    score_list.push_back(std::make_pair(name, w.get_score()));
    sort(score_list.begin(), score_list.end(), [](auto &left, auto &right) {
               return right.second < left.second;
           });
    std::ofstream ofs{"assets/score", std::ofstream::out};
    for(auto item : score_list) {
        ofs << item.first << " " << item.second << '\n';
    }
    ofs.close();
};
