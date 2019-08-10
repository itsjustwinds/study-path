const
        fi='money.inp';
        fo='money.out';
var
        s,s1,k,k1,g,g1:int64;
        kt:boolean;
        i,n:longint;
        f,h:text;
procedure xuly(g1,s1,k1:longint);
begin
        if k-k1>=0 then k:=k-k1
        else
        begin
                k:=k+29-k1;
                dec(s);
                if s<0 then
                begin
                        s:=s+16;
                        dec(g);
                        if g<0 then
                        begin
                                kt:=false;
                                exit;
                        end;
                end;
        end;
        if s-s1>=0 then s:=s-s1
        else begin
                s:=s+16-s1;
                dec(g);
                if g<0 then
                begin
                        kt:=false;
                        exit;
                end;
        end;
        if g-g1>=0 then g:=g-g1
        else begin
                kt:=false;
                exit;
        end;
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        assign(h,fo);
        rewrite(h);
        readln(f,g,s,k);
        readln(f,n);
        kt:=true;
        for i:=1 to n do
        begin
                readln(f,g1,s1,k1);
                xuly(g1,s1,k1);
                if kt=false then
                begin
                        write(h,-1);
                        break;
                end;
        end;
        if kt=true then write(h,g,' ',s,' ',k);
        close(f);
        close(h);
end;
begin
        nhap;
end.