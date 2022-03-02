.export print
print:
    lda $200, x
    cmp #0 ; Null character check
    beq end
    sta $e003
    inx
    jmp print
end:
    rts
