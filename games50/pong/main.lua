-- include push library for rendering retro resolution
push = require 'push'

-- include class library for OOP
Class = require 'class'
        require 'Paddle'
        require 'Ball'

-- environment
WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720
VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

-- atributes
PADDLE_SPEED = 200



-- executes once on start; establishes vars & resources globaly  
function love.load()
    -- initialize Paddle:init(x, y, width, height)
    player1 = Paddle(10, 30, 5, 20)
    player2 = Paddle(VIRTUAL_WIDTH - 10, 30, 5, 20)

    -- initialize Ball:init(x, y, width, height)
    ball = Ball(VIRTUAL_WIDTH / 2 - 2, VIRTUAL_HEIGHT / 2 - 2, 4, 4)

    -- initialize gameState
    gameState = 'start'
end
