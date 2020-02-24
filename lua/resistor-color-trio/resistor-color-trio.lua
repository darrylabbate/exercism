local band = {
    black  = 0,
    brown  = 1,
    red    = 2,
    orange = 3,
    yellow = 4,
    green  = 5,
    blue   = 6,
    violet = 7,
    grey   = 8,
    white  = 9
}

return {
  decode = function(c1, c2, c3)
      local val = (band[c1] * 10 + band[c2]) * 10 ^ band[c3]
      if val > 1000 then
          return val/1000, "kiloohms"
      else
          return val, "ohms"
      end
  end
}
