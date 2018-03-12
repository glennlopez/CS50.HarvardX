-- use the class library
Paddle = Class{}



-- Paddle initialized values
function Paddle:init(x, y, width, height)
    self.x = x
    self.y = y
    self.width = width
    self.height = height
    self.dy = 0
end



-- Paddle frame update
--player1Y = math.max(0, player1Y + -P1_PADDLE_SPEED * dt)
function Paddle:update(dt)
    if self.dy < 0 then
        self.y = math.max(0, self.y + self.dy * dt)
    else
        self.y = math.min(VIRTUAL_HEIGHT - self.height, self.y + self.dy * dt)
    end
end



-- Render Paddle
function Paddle:render()
    love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end