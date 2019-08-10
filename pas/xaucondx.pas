const
        fi='xaucondx.inp';
        fo='xaucondx.out';
var
        s,s1:ansistring;
        i,j,d,t:longint;
        f:text;

procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
end;
function dx(s:ansistring):boolean;
var
        i:longint;
begin
        dx:=false;
        for i:=1 to length(s) div 2 do
                if s[i]<>s[length(s)-i+1] then exit;
        dx:=true;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        t:=0;
        for i:=1 to length(s) do
        begin
                s1:='';
                for j:=i to length(s) do
                begin
                        s1:=s1+s[j];
                        if (dx(s1)) and (pos(s1,s)=i) then inc(t);
                end;
        end;
        write(f,t);
        close(f);
end;
begin
        nhap;
        xuly;
end.
