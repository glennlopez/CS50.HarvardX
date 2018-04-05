-- use the class library 
Ball = Class{}


-- Ball initial values loaded
function Ball:init(x, y, width, height, BALL_SPEED)
    self.x = x
    self.y = y
    self.width = width
    self.height = height
    self.dy = math.random(2) == 1 and -BALL_SPEED or BALL_SPEED
    self.dx = math.random(2) == 1 and math.random(-BALL_SPEED * 0.8, -BALL_SPEED) or math.random(BALL_SPEED * 0.8, BALL_SPEED)
end



-- Ball home/reset value position
function Ball:reset()
    self.x = VIRTUAL_WIDTH / 2 - 2
    self.y = VIRTUAL_HEIGHT / 2 - 2
    self.dy = math.random(2) == 1 and -BALL_SPEED or BALL_SPEED
    self.dx = math.random(-BALL_SPEED/2, BALL_SPEED/2)
end



-- Ball frame update
function Ball:update(dt)
    self.x = self.x + self.dx * dt
    self.y = self.y + self.dy * dt
end


-- Ball render
function Ball:render()
    love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end