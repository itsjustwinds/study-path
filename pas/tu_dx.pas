const
        fi='tu_dx.inp';
        fo='tu_dx.out';
var
        s1:array [1..10000] of string;
        s:string;
        k,i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
end;
function dx(s:string):boolean;
var
        i:longint;
begin   dx:=true;
        for i:=1 to length(s) div 2 do
                if s[i]<>s[length(S)-i+1] then
                begin
                        dx:=false;
                        break;
                end;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        s:=s+' ';
        k:=1;
        for i:=1 to length(s) do
        begin
                if s[i]<>' ' then s1[k]:=s1[k]+s[i]
                else inc(k);
        end;
        for i:=1 to k do
                if dx(s1[i]) then writeln(f,s1[i]);
        close(f);
end;
begin
        nhap;
        xuly;
end.