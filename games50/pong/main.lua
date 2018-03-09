-- include push library for rendering retro resolution
push = require 'push'

-- class libraries
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
    -- establish resources for environment stage
    love.graphics.setDefaultFilter('nearest', 'nearest')

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        resizable = false,
        vsync = true
    })

    -- seed enviroment RNG
    math.randomseed(os.time())

    -- establish + set new font resource
    smallFont = love.graphics.setNewFont('font.ttf', 8)

    -- establish player Paddle(x,y,width,height) resources
    player1 = Paddle(10, 30, 5, 20)
    player2 = Paddle(VIRTUAL_WIDTH - 10, 30, 5, 20)

    -- establish npc Ball(x, y, width, height) resources
    ball = Ball(VIRTUAL_WIDTH / 2 - 2, VIRTUAL_HEIGHT / 2 - 2, 4, 4)

    -- initialize gameState
    gameState = 'start'
end



function love.update(dt)
    -- 
    if gameState == 'play' then
        ball:update(dt)
    end

    player1:update(dt)
    player2:update(dt)
end