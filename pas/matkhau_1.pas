const
        fi='matkhau.inp';
        fo='matkhau.out';
var
        s:ansistring;
        i,j,d:longint;
        ktc,kts,ktcl:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        close(F);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to length(s)-7 do
        begin
                ktc:=false;
                kts:=false;
                ktcl:=false;
                for j:=i to length(s) do
                begin
                        if (s[j] in['0'..'9']) then kts:=true;
                        if (s[j] in ['a'..'z']) then ktc:=true;
                        if (s[j] in['A'..'Z']) then ktcl:=true;
                if (ktc=true) and (kts=true) and(ktcl=true) and (j-i+1>=8)then
                        inc(d);
                end;
        end;
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuly;
end.
