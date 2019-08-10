const
        fi='xoakitu.inp';
        fo='xoakitu.out';
var
        s,s1:string;
        i,k:longint;
        kt:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        readln(f,k);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        repeat
        kt:=true;
        if k>=0 then
        begin
               i:=1;
               while i<=(length(s) div 2) do
               begin
                        if s[i]>s[i+1] then inc(i);
                        if (s[i]<s[i+1]) and (i<=(length(s) div 2)) then
                        begin
                        dec(k);
                        delete(s,i,1);
                        kt:=false;
                        break;
                        end;
               end;
        end;
        if kt=true then
        begin
                        i:=length(s);
                        while i>=(length(s) div 2) do
                        begin
                                if s[i]>s[i-1] then dec(i);
                                if (s[i]<s[i-1]) and (i>=(length(s) div 2)) then
                                begin
                                        dec(k);
                                        delete(s,i,1);
                                        break;
                                end;
                        end;
                end;
        until k=0;
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuat;
end.
