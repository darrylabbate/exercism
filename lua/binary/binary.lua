local function to_decimal(input)
    if input:match("%D") then return 0 end
    local n = 0
    for i=1,#input do
        n = n + input:sub(i,i) * 2^(#input-i)
    end
    return n
end

return {
  to_decimal = to_decimal
}
