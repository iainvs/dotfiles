Clear-Host
function prompt {
    $identity = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($identity)
    $adminRole = [Security.Principal.WindowsBuiltInRole]::Administrator

    if ($principal.IsInRole($adminRole)) {
        Write-Host "λ" -ForegroundColor Red -NoNewline
    }

    else {
    Write-Host "λ" -NoNewline -ForegroundColor Yellow
    }

    return " "
}
