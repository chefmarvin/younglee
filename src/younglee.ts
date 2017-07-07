import * as commander from 'commander';
const pkgJson = require('../package');

commander.version(pkgJson.version)
    .usage('<command> [options]')
    .command('en', 'Display cv in English')
    .command('ch', '显示中文简历')
    .parse(process.argv);
