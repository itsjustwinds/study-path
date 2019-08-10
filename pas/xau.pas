const
        fi='xau.inp';
        fo='xau.out';
var
        s,s1:ansistring;
        f:text;

procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
end;
function dx(s:string):boolean;
var i:longint;
begin
        dx:=true;
        for i:=1 to length(s) div 2 do
                if s[i]<>s[length(s)-i+1] then
                begin
                        dx:=false;
                        break;
                end;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        s:=s+' ';s1:='';
        while s<>'' do
        begin
                while s[1]<>' ' do
                begin
                        s1:=s1+s[1];
                        delete(s,1,1);
                end;
                delete(s,1,1);
                if dx(s1) then write(f,s1,' ');
                s1:='';
        end;
        close(f);
end;
begin
        nhap;
xuly;
end.