const
        fi='xoaso.inp';
        fo='xoaso.out';
var
        s:string;
        i,k:longint;
        t:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s,k);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        t:=false;
        repeat
                for i:=1 to length(s) do
                begin
                        if s[i]<s[i+1] then
                        begin
                                delete(s,i,1);
                                dec(k);
                                break;
                        end;
                        if (i=length(s))and (k<>0) then t:=true;
                end;
        until (k=0) or(t=true);
        if k<>0 then
        repeat
                for i:=length(s) downto 1 do
                        if s[i]<s[i-1] then
                        begin
                                delete(s,i,1);
                                dec(k);
                                break;
                        end;
        until k=0;
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuly;
end.
