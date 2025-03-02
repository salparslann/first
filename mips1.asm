.data
prompt: .asciiz "Please enter two integers: "
msg1: .asciiz " raised to power "
msg2: .asciiz " is "
newline: .asciiz "\n"

.text
.globl main

main:
    # Kullan�c�ya soru sorma
    li $v0, 4
    la $a0, prompt
    syscall

    # �lk tam say�y� al
    li $v0, 5
    syscall
    move $s0, $v0       # �lk say�y� sakla ($s0)
     
    # �kinci tam say�y� al
    li $v0, 5
    syscall
    move $s1, $v0       # �kinci say�y� sakla ($s1)

    move $a0, $s0       # power fonksiyonu i�in ilk parametre (b)
    move $a1, $s1       # power fonksiyonu i�in ikinci parametre (e)
    jal power
    move $t0, $v0       # Sonucu do�rudan $t0'ya kopyala

    # �lk say�y� yazd�r
    move $a0, $s0
    li $v0, 1
    syscall

    # " raised to power " mesaj�n� yazd�r
    li $v0, 4
    la $a0, msg1
    syscall

    # �kinci say�y� yazd�r
    move $a0, $s1
    li $v0, 1
    syscall

    # " is " mesaj�n� yazd�r
    li $v0, 4
    la $a0, msg2
    syscall

    # Sonucu yazd�r
    move $a0, $t0
    li $v0, 1
    syscall

    # Yeni sat�r yazd�r
    li $v0, 4
    la $a0, newline
    syscall

    # ��k��
    li $v0, 10
    syscall

power:
    # Recursive fonksiyon i�in stack'te yer a�
    addi $sp, $sp, -8   
    sw $ra, 4($sp)      
    sw $a1, 0($sp)      

    # E�er e == 0 ise 'case' b�l�m�ne git
    beq $a1, 0, case

    # power(b, e-1) hesapla
    addi $a1, $a1, -1   # e'yi azalt 
    jal power

    # Sonucu b * power(b, e-1) hesapla, b�ylece v main fonksiyonuna geri d�ner
    mul $v0, $a0, $v0  

    # Fonksiyondan ��karken stack'i geri y�kle
    lw $ra, 4($sp)      
    lw $a1, 0($sp)      
    addi $sp, $sp, 8    # stack'i geri y�kle
    jr $ra

case:
    li $v0, 1           # e == 0 ise 1 d�nd�r
    lw $ra, 4($sp)
    lw $a1, 0($sp)
    addi $sp, $sp, 8
    jr $ra
