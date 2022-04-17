.ifndef _PRINT_S_
_PRINT_S_ = 1

.proc print
    pla
    sta return_addr
    pla
    sta return_addr+1

    pla
    tax
    pla
    tay

loop:
    lda $200, x
    cmp #0
    beq end
    sta $e003
    inx
    jmp loop

end:
    lda return_addr+1
    pha
    lda return_addr
    pha
    rts
return_addr: .res 2
.endproc

.endif
