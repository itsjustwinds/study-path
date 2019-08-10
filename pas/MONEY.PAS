const
        fi='money.inp';
        fo='money.out';
var
        i:longint;
        kt:boolean;
        g,s,k,g1,s1,k1,n:int64;
        f,h:text;
procedure xuat;
begin
        if k-k1>=0 then k:=k-k1
        else begin
                k:=k+29;
                dec(s);
                k:=k-k1;
             end;
        if s-s1>=0 then s:=s-s1
        else begin
                s:=s+17;
                dec(g);
                s:=s-s1;
             end;
        if g-g1>=0 then g:=g-g1
        else
                kt:=false;
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        assign(h,fo);
        rewrite(h);
        kt:=true;
        readln(f,g,s,k);
        readln(f,n);
        for i:=1 to n do
        begin
                readln(f,g1,s1,k1);
                xuat;
                if kt=false then break;
        end;
        if kt=true then write(h,g,' ',s,' ',k)
        else write(h,-1);
        close(f);
        close(h);
end;
begin
        nhap;
end.
