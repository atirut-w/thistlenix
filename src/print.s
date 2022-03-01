.export print
print:
    ; The address argument is in the accumulator, but we cannot use the
    ; accumulator as index, so move it to X
    tax
putchar:
    lda $200, x ; TODO: 16 bit address?
    cmp #$0 ; Null character?
    beq end
    sta $e003 ; 0xE003 is the terminal output address
    inx
    jmp putchar
end:
    rts
