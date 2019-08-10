const
        fi='canbang.inp';
        fo='canbang.out';
var
        s:ansistring;
        i,n,x,s1,s2:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        s1:=0;s2:=0;
        for i:=1 to length(s) do
        begin
                val(s[i],n,x);
                if n mod 2<>0 then s1:=s1+n;
                if n mod 2=0 then s2:=s2+n;
        end;
        if s1=s2 then write(f,'co')
        else write(f,'khong');
        close(f);
end;
begin
        nhap;
        xuat;
end.
