local M = {}

M.base_30 = {
  white = "#fbf1c7",
  black = "#000000",
  black2 = "#2e2e2e",
  one_bg = "#353535",
  one_bg2 = "#3f3f3f",
  one_bg3 = "#444444",
  grey = "#4b4b4b",
  grey_fg = "#4e4e4e",
  grey_fg2 = "#505050",
  light_grey = "#656565",
  red = "#fb4934",
  baby_pink = "#cc241d",
  pink = "#ff75a0",
  line = "#36393a",
  green = "#b8bb26",
  vibrant_green = "#a9b665",
  nord_blue = "#83a598",
  blue = "#458588",
  yellow = "#d79921",
  sun = "#dfab01",
  purple = "#b4bbc8",
  dark_purple = "#d3869b",
  teal = "#749689",
  orange = "#e78a4e",
  cyan = "#82b3a8",
  pmenu_bg = "#83a598",
  folder_bg = "#dfab01"
}

M.base_16 = {
  base00 = "#000000",
  base01 = "#3c3836",
  base02 = "#423e3c",
  base03 = "#484442",
  base04 = "#bdae93",
  base05 = "#d5c4a1",
  base06 = "#fbf1c7",
  base07 = "#fbf1c7",
  base08 = "#cc241d",
  base09 = "#fe8019",
  base0A = "#dfab01",
  base0B = "#b8bb26",
  base0C = "#8ec07c",
  base0D = "#83a598",
  base0E = "#d3869b",
  base0F = "#d65d0e"
}

M.type = "dark"

M = require("base46").override_theme(M, "gruvbox")

M.highlights = {
  syntax = {
    Operator = { fg = M.base_30.nord_blue },
  },

  treesitter = {
    ["@operator"] = { fg = M.base_30.nord_blue },
  },

  VertSplit = { bg = "NONE", fg = "NONE" },
  NonText = { fg = "NONE" },
  WinSeparator = { bg = "NONE", fg = "NONE" },
}

return M

