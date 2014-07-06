#!/usr/bin/perl -w
use strict;

my $szIniFile = "epic.ini";

open(INI, "<epic.ini") || die("!!! Unable to open file for writing. $!");

while (<INI>) {
  chomp;

    print "\n <!-- $_ \n";
    print "   -->\n";
  if ( /=/ ) {
    my ($szName, $szStats) = split('=', $_);
    my ($szCost, $szMove, $szSavingThrow, $szCAF, $szWeapon, $szRange, $szAttackDice, $szToHit, $szTargetSaveMod) = split('\\\n', $szStats);
    print "<Unit Name=\"$szName\">\n";
    print "  <Cost>$szCost</Cost>\n";
    print "  <Move>$szMove</Move>\n";
    print "  <SavingThrow>$szSavingThrow</SavingThrow>\n";
    print "  <CloseAssaultFactor>$szCAF</CloseAssaultFactor>\n";
    print "  <Weapon Name=\"$szWeapon\" Range=\"$szRange\" AttackDice=\"$szAttackDice\" ToHit=\"$szToHit\" TargetSaveMod=\"$szTargetSaveMod\"></Weapon>\n";
    print "  <Type></Type>\n";
    print "  <Notes></Notes>\n";
    print "</Unit>\n";
  }
}

close(INI);
