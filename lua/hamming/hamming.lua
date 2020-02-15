local Hamming = {}

function Hamming.compute(a,b)
    if #a ~= #b then return -1 end
    local d = 0
    for i=1,#a do
        if a:sub(i,i) ~= b:sub(i,i) then
            d = d + 1
        end
    end
    return d
end

return Hamming
