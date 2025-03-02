.data
prompt: .asciiz "Please enter two integers: "
msg1: .asciiz " raised to power "
msg2: .asciiz " is "
newline: .asciiz "\n"

.text
.globl main

main:
    # Kullanýcýya soru sorma
    li $v0, 4
    la $a0, prompt
    syscall

    # Ýlk tam sayýyý al
    li $v0, 5
    syscall
    move $s0, $v0       # Ýlk sayýyý sakla ($s0)
     
    # Ýkinci tam sayýyý al
    li $v0, 5
    syscall
    move $s1, $v0       # Ýkinci sayýyý sakla ($s1)

    move $a0, $s0       # power fonksiyonu için ilk parametre (b)
    move $a1, $s1       # power fonksiyonu için ikinci parametre (e)
    jal power
    move $t0, $v0       # Sonucu doðrudan $t0'ya kopyala

    # Ýlk sayýyý yazdýr
    move $a0, $s0
    li $v0, 1
    syscall

    # " raised to power " mesajýný yazdýr
    li $v0, 4
    la $a0, msg1
    syscall

    # Ýkinci sayýyý yazdýr
    move $a0, $s1
    li $v0, 1
    syscall

    # " is " mesajýný yazdýr
    li $v0, 4
    la $a0, msg2
    syscall

    # Sonucu yazdýr
    move $a0, $t0
    li $v0, 1
    syscall

    # Yeni satýr yazdýr
    li $v0, 4
    la $a0, newline
    syscall

    # Çýkýþ
    li $v0, 10
    syscall

power:
    # Recursive fonksiyon için stack'te yer aç
    addi $sp, $sp, -8   
    sw $ra, 4($sp)      
    sw $a1, 0($sp)      

    # Eðer e == 0 ise 'case' bölümüne git
    beq $a1, 0, case

    # power(b, e-1) hesapla
    addi $a1, $a1, -1   # e'yi azalt 
    jal power

    # Sonucu b * power(b, e-1) hesapla, böylece v main fonksiyonuna geri döner
    mul $v0, $a0, $v0  

    # Fonksiyondan çýkarken stack'i geri yükle
    lw $ra, 4($sp)      
    lw $a1, 0($sp)      
    addi $sp, $sp, 8    # stack'i geri yükle
    jr $ra

case:
    li $v0, 1           # e == 0 ise 1 döndür
    lw $ra, 4($sp)
    lw $a1, 0($sp)
    addi $sp, $sp, 8
    jr $ra
