local execute = vim.api.nvim_command
local fn = vim.fn

local install_path = fn.stdpath('data')..'/site/pack/packer/start/packer.nvim'

if fn.empty(fn.glob(install_path)) > 0 then
	fn.system({'git', 'clone', 'https://github.com/wbthomason/packer.nvim', install_path})
	execute 'packadd packer.nvim'
end

return require('packer').startup(function()
	use "wbthomason/packer.nvim"

	-- theme
	use "navarasu/onedark.nvim"

	-- statusbar
	use {
		"hoob3rt/lualine.nvim",
		config = function()
			require("config.statusbar")
		end,
	}

	-- autopairs
	use {
		"windwp/nvim-autopairs",
		config = function()
			require("config.autopairs")
		end,
	}

	-- comments
	use {
		'b3nj5m1n/kommentary',
		config = function()
			require("config.comments")
		end,
	}

	use {
		'windwp/nvim-ts-autotag',
		config = function()
			require("config.comments")
		end,
	}

	-- indent
	use {
		"lukas-reineke/indent-blankline.nvim",
		event = "BufRead",
		config = function()
			require("config.indentline")
		end
	}

	-- color
	use {
		"rrethy/vim-hexokinase",
		event = "BufRead",
		run = "make hexokinase",
	}

	-- icons
	use {
		"kyazdani42/nvim-web-devicons",
		config = function()
			require("config.icons")
		end,
	}
	-- formatting
	use {
		"lukas-reineke/format.nvim",
		config = function ()
			require("config.others")
		end,
	}

	-- file browser
	use {
		"kyazdani42/nvim-tree.lua",
		config = function()
			require("config.nvimtree")
		end,
	}

	-- lsp
	use {
		"neovim/nvim-lspconfig",
		requires = "kabouzeid/nvim-lspinstall",
		config = function()
			require("config.lspconfig")
		end
	}

	-- treesitter
	use {
		"nvim-treesitter/nvim-treesitter-textobjects",
		requires = "nvim-treesitter/nvim-treesitter",
		config = function()
			require("config.treesitter")
		end
	}

	-- completion and snippet
	use {
		"hrsh7th/nvim-cmp",
		requires = {
			"rafamadriz/friendly-snippets",
			"L3MON4D3/LuaSnip",
			"hrsh7th/cmp-buffer",
			"hrsh7th/cmp-path",
		}
	}

	use {
		'glepnir/lspsaga.nvim',
	}

	use {
		"hrsh7th/cmp-nvim-lsp",
	}

	use {
		"onsails/lspkind-nvim",
	}

	use {
		"lewis6991/gitsigns.nvim",
		requires = {
			"nvim-lua/plenary.nvim"
		},
		config = function()
			require('config.git')
		end,
	}

	use {
		"ray-x/lsp_signature.nvim",
		config = function()
			require('config.others')
		end,
	}
	use {
		"mattn/emmet-vim"
	}
end)
