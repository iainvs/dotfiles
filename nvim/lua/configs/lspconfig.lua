local nvlsp = require "nvchad.configs.lspconfig"

local servers = { "html", "cssls", "tinymist" }
vim.lsp.enable(servers)

for _, lsp in ipairs(servers) do
  vim.lsp.config(lsp, {
    install = {
      package = lsp,
    },
    config = {
      on_attach = nvlsp.on_attach,
      on_init = nvlsp.on_init,
      capabilities = nvlsp.capabilities,
      settings = {
        exportPdf = "onSave",
        outputPath = "$root/$dir/$name.pdf",
        semanticTokens = "enable"
      },
    },
  })
  
  -- Enable the config
  vim.lsp.enable(lsp)
end
