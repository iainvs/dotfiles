**Structure**
```
lua
	configs
		conform.lua
		lazy.lua
		lspconfig.lua
	plugins
		init.lua
	autocmds.lua
	chadrc.lua
	mappings.lua
	options.lua
.stylua.toml
init.lua
lazy-lock.json
```
1. `lazy-lock.json` <span style="color: var(--red)">[DO NOT MODIFY.]</span>
	- Tracks every single plugin installed with their commits, tags, and branches for the configs to be easily replicated.
2. `init.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	**Structure**
	```
``` lua
		-- maps base46_cache to a location in your system to load themes
vim.g.base46_cache = vim.fn.stdpath "data" .. "/base46/"

-- maps mapleader to a character(space)
vim.g.mapleader = " "

-- maps lazypath to a location where lazy.nvim is stored locally
local lazypath = vim.fn.stdpath "data" .. "/lazy/lazy.nvim"

-- checks for lazy.nvim and installs from gh if not found
if not vim.uv.fs_stat(lazypath) then
  local repo = "https://github.com/folke/lazy.nvim.git"
  vim.fn.system { "git", "clone", "--filter=blob:none", repo, "--branch=stable", lazypath }
end

-- loads lazy.nvim before anything else
vim.opt.rtp:prepend(lazypath)

-- maps lazy_config to the directory configs/lazy.lua locally
local lazy_config = require "configs.lazy"

-- load plugins
require("lazy").setup({ -- start lazy.nvim with the following configs
  {
    "NvChad/NvChad",  -- main repo
    lazy = false, -- load immediately
    branch = "v2.5",
    import = "nvchad.plugins",  -- import from nvchad.plugins
  },

  { import = "plugins" }, -- read folder plugins to import
}, lazy_config) -- pass as lazy.nvim config

-- load theme
dofile(vim.g.base46_cache .. "defaults")
dofile(vim.g.base46_cache .. "statusline")

require "options" -- use options.lua
require "autocmds" -- use autocmds.lua

vim.schedule(function()
  require "mappings" -- use mappings.lua
end)

```
3. `.stylua.toml` <span style="color: var(--green)">[EDITED]</span>
	- Basic text configs
4. `lua/autocmds.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- Automated actions like formatting, linting, and testing on file save
5. `lua/chadrc.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- UI & base46 configs
6. `lua/mappings.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- Custom keybinds
7. `lua/options.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- General settings for the editor
8. `lua/configs/conform.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- File-specific formatting
9. `lua/configs/lazy.lua` <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- Other objects to load
10. `lua/configs/lspconfig.lua` <span style="color: var(--orange)">[HIGH PRIORITY.]</span> <span style="color: var(--yellow)">[TO BE EDITED.]</span> 
	- LSPs
11. `lua/plugins/init.lua` <span style="color: var(--orange)">[HIGH PRIORITY.] </span> <span style="color: var(--yellow)">[TO BE EDITED.]</span>
	- Loads plugins