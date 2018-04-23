
-- default FPS display
function displayFPS()
    -- simple FPS display across all states
    --love.graphics.setFont(smallFont)
    love.graphics.setColor(0, 255, 0, 255)
    love.graphics.print('FPS: ' .. tostring(love.timer.getFPS()), 10, 10)
end

-- display FPS using custom rgb
function rgbFPS(r,g,b)
    -- simple FPS display across all states
    --love.graphics.setFont(smallFont)
    love.graphics.setColor(r, g, b, 255)
    love.graphics.print('FPS: ' .. tostring(love.timer.getFPS()), 10, 10)
end